/**
 * Autogenerated by Thrift Compiler (0.8.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Config_H
#define Config_H

#include <TProcessor.h>
#include "auditevent_types.h"



class ConfigIf {
 public:
  virtual ~ConfigIf() {}
  virtual void registerNewServer(ConfigMessage& _return, const ConfigMessage& config) = 0;
  virtual void getConfig(ConfigMessage& _return, const ConfigMessage& config) = 0;
};

class ConfigIfFactory {
 public:
  typedef ConfigIf Handler;

  virtual ~ConfigIfFactory() {}

  virtual ConfigIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ConfigIf* /* handler */) = 0;
};

class ConfigIfSingletonFactory : virtual public ConfigIfFactory {
 public:
  ConfigIfSingletonFactory(const boost::shared_ptr<ConfigIf>& iface) : iface_(iface) {}
  virtual ~ConfigIfSingletonFactory() {}

  virtual ConfigIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ConfigIf* /* handler */) {}

 protected:
  boost::shared_ptr<ConfigIf> iface_;
};

class ConfigNull : virtual public ConfigIf {
 public:
  virtual ~ConfigNull() {}
  void registerNewServer(ConfigMessage& /* _return */, const ConfigMessage& /* config */) {
    return;
  }
  void getConfig(ConfigMessage& /* _return */, const ConfigMessage& /* config */) {
    return;
  }
};

typedef struct _Config_registerNewServer_args__isset {
  _Config_registerNewServer_args__isset() : config(false) {}
  bool config;
} _Config_registerNewServer_args__isset;

class Config_registerNewServer_args {
 public:

  Config_registerNewServer_args() {
  }

  virtual ~Config_registerNewServer_args() throw() {}

  ConfigMessage config;

  _Config_registerNewServer_args__isset __isset;

  void __set_config(const ConfigMessage& val) {
    config = val;
  }

  bool operator == (const Config_registerNewServer_args & rhs) const
  {
    if (!(config == rhs.config))
      return false;
    return true;
  }
  bool operator != (const Config_registerNewServer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Config_registerNewServer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Config_registerNewServer_pargs {
 public:


  virtual ~Config_registerNewServer_pargs() throw() {}

  const ConfigMessage* config;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Config_registerNewServer_result__isset {
  _Config_registerNewServer_result__isset() : success(false) {}
  bool success;
} _Config_registerNewServer_result__isset;

class Config_registerNewServer_result {
 public:

  Config_registerNewServer_result() {
  }

  virtual ~Config_registerNewServer_result() throw() {}

  ConfigMessage success;

  _Config_registerNewServer_result__isset __isset;

  void __set_success(const ConfigMessage& val) {
    success = val;
  }

  bool operator == (const Config_registerNewServer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Config_registerNewServer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Config_registerNewServer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Config_registerNewServer_presult__isset {
  _Config_registerNewServer_presult__isset() : success(false) {}
  bool success;
} _Config_registerNewServer_presult__isset;

class Config_registerNewServer_presult {
 public:


  virtual ~Config_registerNewServer_presult() throw() {}

  ConfigMessage* success;

  _Config_registerNewServer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Config_getConfig_args__isset {
  _Config_getConfig_args__isset() : config(false) {}
  bool config;
} _Config_getConfig_args__isset;

class Config_getConfig_args {
 public:

  Config_getConfig_args() {
  }

  virtual ~Config_getConfig_args() throw() {}

  ConfigMessage config;

  _Config_getConfig_args__isset __isset;

  void __set_config(const ConfigMessage& val) {
    config = val;
  }

  bool operator == (const Config_getConfig_args & rhs) const
  {
    if (!(config == rhs.config))
      return false;
    return true;
  }
  bool operator != (const Config_getConfig_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Config_getConfig_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Config_getConfig_pargs {
 public:


  virtual ~Config_getConfig_pargs() throw() {}

  const ConfigMessage* config;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Config_getConfig_result__isset {
  _Config_getConfig_result__isset() : success(false) {}
  bool success;
} _Config_getConfig_result__isset;

class Config_getConfig_result {
 public:

  Config_getConfig_result() {
  }

  virtual ~Config_getConfig_result() throw() {}

  ConfigMessage success;

  _Config_getConfig_result__isset __isset;

  void __set_success(const ConfigMessage& val) {
    success = val;
  }

  bool operator == (const Config_getConfig_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Config_getConfig_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Config_getConfig_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Config_getConfig_presult__isset {
  _Config_getConfig_presult__isset() : success(false) {}
  bool success;
} _Config_getConfig_presult__isset;

class Config_getConfig_presult {
 public:


  virtual ~Config_getConfig_presult() throw() {}

  ConfigMessage* success;

  _Config_getConfig_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ConfigClient : virtual public ConfigIf {
 public:
  ConfigClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  ConfigClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void registerNewServer(ConfigMessage& _return, const ConfigMessage& config);
  void send_registerNewServer(const ConfigMessage& config);
  void recv_registerNewServer(ConfigMessage& _return);
  void getConfig(ConfigMessage& _return, const ConfigMessage& config);
  void send_getConfig(const ConfigMessage& config);
  void recv_getConfig(ConfigMessage& _return);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ConfigProcessor : public ::apache::thrift::TProcessor {
 protected:
  boost::shared_ptr<ConfigIf> iface_;
  virtual bool process_fn(apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, std::string& fname, int32_t seqid, void* callContext);
 private:
  std::map<std::string, void (ConfigProcessor::*)(int32_t, apache::thrift::protocol::TProtocol*, apache::thrift::protocol::TProtocol*, void*)> processMap_;
  void process_registerNewServer(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getConfig(int32_t seqid, apache::thrift::protocol::TProtocol* iprot, apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ConfigProcessor(boost::shared_ptr<ConfigIf> iface) :
    iface_(iface) {
    processMap_["registerNewServer"] = &ConfigProcessor::process_registerNewServer;
    processMap_["getConfig"] = &ConfigProcessor::process_getConfig;
  }

  virtual bool process(boost::shared_ptr<apache::thrift::protocol::TProtocol> piprot, boost::shared_ptr<apache::thrift::protocol::TProtocol> poprot, void* callContext);
  virtual ~ConfigProcessor() {}
};

class ConfigProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ConfigProcessorFactory(const ::boost::shared_ptr< ConfigIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ConfigIfFactory > handlerFactory_;
};

class ConfigMultiface : virtual public ConfigIf {
 public:
  ConfigMultiface(std::vector<boost::shared_ptr<ConfigIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ConfigMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ConfigIf> > ifaces_;
  ConfigMultiface() {}
  void add(boost::shared_ptr<ConfigIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void registerNewServer(ConfigMessage& _return, const ConfigMessage& config) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->registerNewServer(_return, config);
        return;
      } else {
        ifaces_[i]->registerNewServer(_return, config);
      }
    }
  }

  void getConfig(ConfigMessage& _return, const ConfigMessage& config) {
    size_t sz = ifaces_.size();
    for (size_t i = 0; i < sz; ++i) {
      if (i == sz - 1) {
        ifaces_[i]->getConfig(_return, config);
        return;
      } else {
        ifaces_[i]->getConfig(_return, config);
      }
    }
  }

};



#endif
