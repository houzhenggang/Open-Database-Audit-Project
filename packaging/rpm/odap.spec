#%define _topdir	 	/home/rob/rpm
%define name		odap-client
%define release		1
%define version 	0.9
%define buildroot %{_topdir}/%{name}-%{version}-root

Name:           %{name}
Release:        %{release}
Version:	%{version}
Summary:        Open Database Audit Project client capture program
BuildRoot:	${buildroot}

Group:          Database/Auditing
License:        GNU/GPL
URL:            http://www.opendbaudit.com

%description
Database Auditing Software

%build
make

%install
make install prefix=$RPM_BUILD_ROOT

%files
%defattr(-,root,root)
/opt/dbauditcloud/bin/CloudCapture
/opt/dbauditcloud/bin/certificate.pem
/opt/dbauditcloud/bin/log4j.properties
/opt/dbauditcloud/kernel/dbaudit.ko
/etc/init.d/dbauditcloud
/opt/dbauditcloud/bin/dbauditcloud-daemon