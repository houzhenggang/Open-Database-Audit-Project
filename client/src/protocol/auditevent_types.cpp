/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "auditevent_types.h"



const char* Event::ascii_fingerprint = "542F33A9BF309362330EA11E1F0C61C6";
const uint8_t Event::binary_fingerprint[16] = {0x54,0x2F,0x33,0xA9,0xBF,0x30,0x93,0x62,0x33,0x0E,0xA1,0x1E,0x1F,0x0C,0x61,0xC6};

uint32_t Event::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->src_ip);
          this->__isset.src_ip = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->src_port);
          this->__isset.src_port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->timestamp);
          this->__isset.timestamp = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->statement);
          this->__isset.statement = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->dbname);
          this->__isset.dbname = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appname);
          this->__isset.appname = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->username);
          this->__isset.username = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->row_count);
          this->__isset.row_count = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Event::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Event");
  xfer += oprot->writeFieldBegin("src_ip", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->src_ip);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("src_port", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->src_port);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("timestamp", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->timestamp);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("statement", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->statement);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("dbname", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->dbname);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("appname", ::apache::thrift::protocol::T_STRING, 7);
  xfer += oprot->writeString(this->appname);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("username", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeString(this->username);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("row_count", ::apache::thrift::protocol::T_I32, 9);
  xfer += oprot->writeI32(this->row_count);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* Message::ascii_fingerprint = "CC278EFA43BE452B2842AFA45704DE57";
const uint8_t Message::binary_fingerprint[16] = {0xCC,0x27,0x8E,0xFA,0x43,0xBE,0x45,0x2B,0x28,0x42,0xAF,0xA4,0x57,0x04,0xDE,0x57};

uint32_t Message::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->server_id);
          this->__isset.server_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->token);
          this->__isset.token = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->events.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            iprot->readListBegin(_etype3, _size0);
            this->events.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += this->events[_i4].read(iprot);
            }
            iprot->readListEnd();
          }
          this->__isset.events = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Message::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("Message");
  xfer += oprot->writeFieldBegin("server_id", ::apache::thrift::protocol::T_I16, 1);
  xfer += oprot->writeI16(this->server_id);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("token", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->token);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("events", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->events.size()));
    std::vector<Event> ::const_iterator _iter5;
    for (_iter5 = this->events.begin(); _iter5 != this->events.end(); ++_iter5)
    {
      xfer += (*_iter5).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

const char* ConfigMessage::ascii_fingerprint = "DBC00FA976841D550591C52A6277AC63";
const uint8_t ConfigMessage::binary_fingerprint[16] = {0xDB,0xC0,0x0F,0xA9,0x76,0x84,0x1D,0x55,0x05,0x91,0xC5,0x2A,0x62,0x77,0xAC,0x63};

uint32_t ConfigMessage::read(::apache::thrift::protocol::TProtocol* iprot) {

  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->username);
          this->__isset.username = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->password);
          this->__isset.password = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->server_software);
          this->__isset.server_software = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->port);
          this->__isset.port = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->server_name);
          this->__isset.server_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->timezone_offset);
          this->__isset.timezone_offset = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->strip_predicates);
          this->__isset.strip_predicates = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->token);
          this->__isset.token = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->server_id);
          this->__isset.server_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->server);
          this->__isset.server = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ConfigMessage::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  xfer += oprot->writeStructBegin("ConfigMessage");
  xfer += oprot->writeFieldBegin("username", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->username);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("password", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->password);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("server_software", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->server_software);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("port", ::apache::thrift::protocol::T_I16, 4);
  xfer += oprot->writeI16(this->port);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("server_name", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->server_name);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("timezone_offset", ::apache::thrift::protocol::T_DOUBLE, 6);
  xfer += oprot->writeDouble(this->timezone_offset);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("strip_predicates", ::apache::thrift::protocol::T_BOOL, 7);
  xfer += oprot->writeBool(this->strip_predicates);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("token", ::apache::thrift::protocol::T_STRING, 8);
  xfer += oprot->writeString(this->token);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("server_id", ::apache::thrift::protocol::T_I16, 9);
  xfer += oprot->writeI16(this->server_id);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldBegin("server", ::apache::thrift::protocol::T_STRING, 10);
  xfer += oprot->writeString(this->server);
  xfer += oprot->writeFieldEnd();
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


