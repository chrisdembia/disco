// Copyright (C) 2013 Chris Dembia.

#include "framework/LogImpl.h"

using std::cerr;
using std::endl;
    
framework::Ptr<framework::Log> log() { 
    return framework::LogImpl::log();
}

namespace framework {

framework::Ptr<framework::Log> LogImpl::_log = NULL;

framework::Ptr<framework::Log> LogImpl::log() {

    if (_log == NULL) 
        _log = new LogImpl();

    return _log;

}


void 
LogImpl::entryNew(Priority priority,
                  NamedInterface * obj,
                  const string& funcName,
                  const string& cond) throw() {
    cerr << "'" << obj->name() << "'" << "." << funcName << "(): " << cond <<
        endl;
}

void 
LogImpl::entryNew(Priority priority,
                  const string& funcName,
                  const string& cond) throw () {
    cerr << funcName << "(): " << cond << endl;        
}

void 
LogImpl::entryNew(Priority priority,
                  const string& cond) throw() {
    cerr << cond << endl;        
}

} // namespace framework
