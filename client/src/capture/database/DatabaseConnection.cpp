/* 
 *   This file is part of the Open Database Audit Project (ODAP).
 *
 *   ODAP is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Foobar is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   The code was developed by Rob Williams
 */

#include "DatabaseConnection.h"
#include <time.h>
#include <string.h>
#include <boost/algorithm/string.hpp>
#include <sys/types.h>
#include <pwd.h>
#include <boost/tokenizer.hpp>
#include "../../EventQueue.h"
extern EventQueue event_queue;

LoggerPtr  DatabaseConnection::logger(Logger::getLogger("com.dbaudit.DatabaseConnection"));
extern int server_id;
extern string token;

DatabaseConnection::DatabaseConnection() {
	LOG4CXX_DEBUG(logger,"DatabaseConnection()");
	packet_data_length = 0;
}

DatabaseConnection::~DatabaseConnection() {
	LOG4CXX_DEBUG(logger,"~DatabaseConnection()");
}

string DatabaseConnection::remove_predicates(regex& re,const string & input){
    boost::match_results<std::string::const_iterator> what;
    boost::match_flag_type flags = boost::match_default;
    std::string::const_iterator s = input.begin();
    std::string::const_iterator e = input.end();

    string result = input;
    int adjust = 0;
    int result_subtract = 0;
    while (boost::regex_search(s,e,what,re,flags)){
        std::string::difference_type l = what.length();
        std::string::difference_type p = what.position();
        s += p + l;

        int start_of_number = 0;
        if(input[what.position()+adjust+start_of_number] != '\'' && input[what.position()+adjust+start_of_number] != '"' && isdigit(input[0]) == 0){
        	while(start_of_number < what.length() && (isdigit(input[what.position()+adjust+start_of_number]) == 0) ){
        		start_of_number++;
        	}
        }
       result.replace(what.position()+adjust+start_of_number-result_subtract,what.length()-start_of_number,"?");
        adjust += what.position()+what.length() ;
        result_subtract += what.length()-start_of_number-1 ;
    }

    return result;
}


bool DatabaseConnection::parse(const u_char *packet, pcap_pkthdr *header, int packet_offset)
{
	LOG4CXX_DEBUG(logger,"In DatabaseConnection::parse()");

	//First parse the header for non DBMS specific information
	parseHeader(packet,header,packet_offset);

	//As were not looking at responses yet parse the request
	bool rc = parseRequest(0);

	LOG4CXX_DEBUG(logger,"Exiting DatabaseConnection::parse()");



	return rc;
}

bool DatabaseConnection::parse_format_2(char * data, int len){
	LOG4CXX_DEBUG(logger,"In DatabaseConnection::parse_format_2() :" << len) ;
	//59:5423:501:1323670440:620781428,DB2INST1:select * from staff


	std::vector<std::string> strs;
	string str_data = data;
	boost::split(strs, str_data, boost::is_any_of(":"));

	if(strs.size() > 6){
		event.src_ip = "127.0.0.1";
		event.src_port = atol(strs[1].c_str());

		event_timestamp event_ts;
	    event_ts.event_in_s = atol(strs[3].c_str());
	    event_ts.event_in_ms = atol(strs[4].c_str());
		CachedUserInfo userInfo = userManager.getUserInfo(event.src_ip,strs[1]);

		string statement = "";
		int i = 6;
		while(i < strs.size()){
			statement += strs[i++];
		}

		statement = statement.substr(0,statement.size()-1);
		userManager.regStatement(event.src_ip,strs[1],statement);

		LOG4CXX_DEBUG(logger,"Statement " << statement);


		//Lets check if it's a duplicate
		if(userInfo.getEventTimestamp().event_in_s != 0 && (event_ts.event_in_s - userInfo.getEventTimestamp().event_in_s ) < 2){

			if( ((event_ts.event_in_s - userInfo.getEventTimestamp().event_in_s)*1000000000 + event_ts.event_in_ms - event_ts.event_in_ms) > 1000000 ){
				LOG4CXX_DEBUG(logger,"Duplicate detected: " << ((event_ts.event_in_s - userInfo.getEventTimestamp().event_in_s)*1000000000 + event_ts.event_in_ms - event_ts.event_in_ms) );
			    event_ts.event_in_s = 0;
			    event_ts.event_in_ms = 0;
			    userManager.regEventTimestamp(event.src_ip,strs[1],event_ts);
			    return true;
			}
		}else{
			userManager.regEventTimestamp(event.src_ip,strs[1],event_ts);
		}

		if(userInfo.getUsername().empty()){
			uid_t uid = atoi(strs[2].c_str());
			struct passwd * account = getpwuid(uid);
		}

		userManager.regAppName(event.src_ip,strs[1],"db2bp");



		boost::tokenizer<boost::char_separator<char> > tok(statement);
		i = 0;
		for (boost::tokenizer<boost::char_separator<char> >::iterator it = tok.begin(); it != tok.end(); ++it,i++){
			LOG4CXX_DEBUG(logger,"Token is " << *it);
			if( i == 0 &&strcasecmp((*it).c_str(),"connect") == 0 ){
				LOG4CXX_DEBUG(logger,"Processing connect");
				continue;
			}

			if( i == 0 &&strcasecmp((*it).c_str(),"terminate") == 0  ){
				LOG4CXX_DEBUG(logger,"Terminate processed");
				userManager.regUsername(event.src_ip,strs[1],"");
				break;
			}
			if( i == 1 &&strcasecmp((*it).c_str(),"to")  == 0 ){
				LOG4CXX_DEBUG(logger,"We have a connect statement");
				continue;
			}

			if( i == 2 ){
				userManager.regDBName(event.src_ip,strs[1],*it);
				continue;
			}

			if( i == 3 && strcasecmp((*it).c_str(),"user")   == 0  ){
				continue;
			}

			if( i == 4 ){
				LOG4CXX_DEBUG(logger,"Username specified " << *it);
				userManager.regUsername(event.src_ip,strs[1],*it);
			}
			break;
		}


		userManager.loadEventAttributes(event.src_ip,strs[1],event);
		LOG4CXX_DEBUG(logger,"Event: " << event.statement);

		event_queue.addMessage(event);
	}
	LOG4CXX_DEBUG(logger,"Exiting DatabaseConnection::parse_format_2()");
	return true;
}

//TODO multiple packets in 1 read
bool DatabaseConnection::parse(  char *data, int len){

	LOG4CXX_DEBUG(logger,"In DatabaseConnection::parse() :" << len) ;
	if(len < 1){
		return false;
	}
	packet_data_length = len;
	int offset_describe = 0;
	int frame_offset = 0;
	// Reverse parse to find @ then move forward
	if(*(data) == '@'){
		LOG4CXX_DEBUG(logger,"Found describe packet " );


		while(*(data+offset_describe) == '@' && offset_describe < len){
			string end = (data+offset_describe);
			if(len > 5){
				if(end.size() > 5 && end.at(1) == ' ' && end.at(2) == '[' && end.find_first_of('-') != -1){
					event.appname = "mysql";
					event.src_ip = "127.0.0.1";

					event.appname = end.substr(3,end.find_first_of(':')-3);
					string port = end.substr(end.find_first_of(':')+1,(end.find_first_of('-') - (end.find_first_of(':')+1)));
					event.src_port = (short)atoi(port.c_str());
					frame_offset = end.find_first_of(']')+2;

					event_timestamp event_ts;
				    event_ts.event_in_s = std::time(0);
				    event_ts.event_in_ms = 0;
					userManager.regEventTimestamp(event.src_ip,port,event_ts);
					userManager.regAppName(event.src_ip,port,event.appname);
				}
			}



			int start_of_packet = end.find_first_of(':',frame_offset);
			packet_data_length = atoi(end.substr(frame_offset,start_of_packet-frame_offset).c_str());
			LOG4CXX_DEBUG(logger,"SRC Packet size:" << end.substr(frame_offset,start_of_packet-frame_offset) << ":" << packet_data_length);


			memcpy(packet_data,data+start_of_packet+1+offset_describe,packet_data_length);

			parseRequest(0);

			offset_describe = offset_describe + start_of_packet+1+packet_data_length;
		}
		LOG4CXX_DEBUG(logger,"Exiting DatabaseConnection::parse()");
		return true;
	}else{


		memcpy(packet_data,data+offset_describe,len-offset_describe);

		bool rc = parseRequest(0);

		LOG4CXX_DEBUG(logger,"Exiting DatabaseConnection::parse()");
		return rc;
	}
}

void DatabaseConnection::parseHeader(const u_char * packet,pcap_pkthdr * header,int data_offset)
{
	LOG4CXX_DEBUG(logger,"In DatabaseConnection::parseHeader()" );
	packet+=data_offset;
	ip_pkt = (struct ip*)(packet + sizeof(struct ether_header));
	tcp_pkt = (tcphdr*)( packet + sizeof(struct ether_header) +  sizeof(struct ip) );

	packet_data_length = header->len-((sizeof(struct ether_header) +  sizeof(struct ip) + sizeof(struct tcphdr))+12)-data_offset;

	char buffer[64];
	sprintf(buffer,"%s",inet_ntoa(ip_pkt->ip_src));
	event.src_ip = buffer;
	LOG4CXX_DEBUG(logger,"Source IP:" + event.src_ip);

	sprintf(buffer,"%d",ntohs(tcp_pkt->source));
	event.src_port = ntohs(tcp_pkt->source);
	LOG4CXX_DEBUG(logger,L"Source Port:" << (unsigned short)event.src_port);
	event.timestamp = std::time(0);

	memcpy(packet_data,packet+(sizeof(struct ether_header) +  sizeof(struct ip) + sizeof(struct tcphdr))+12,packet_data_length);

	packet_flag =  *(packet + sizeof(struct ether_header)+  sizeof(struct ip) + 13);

	userManager.tcp_flag(event.src_ip,itoa(event.src_port, 10),packet_flag);
	LOG4CXX_DEBUG(logger,L"Packet TCP Flag:" << packet_flag);

	LOG4CXX_DEBUG(logger,"Exiting DatabaseConnection::parseHeader()");
}

std::string DatabaseConnection::itoa(int value, int base)
{
	enum { kMaxDigits = 35 };

	std::string buf;

	buf.reserve( kMaxDigits ); // Pre-allocate enough space.

	// check that the base if valid

	if (base < 2 || base > 16) return buf;

	int quotient = value;

	// Translating number to string with base:

	do {
		buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
		quotient /= base;
	} while ( quotient );

	// Append the negative sign for base 10
	if ( value < 0 && base == 10) buf += '-';
	std::reverse( buf.begin(), buf.end() );

	return buf;
}





