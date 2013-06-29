// Copyright (C) 2013 Chris Dembia.

#include "DiscoLog.h"

using std::cerr;
using std::endl;
    
framework::Ptr<framework::Log> log() { 
    return framework::DiscoLog::log();
}

namespace framework {

framework::Ptr<framework::Log> DiscoLog::_log = NULL;

framework::Ptr<framework::Log> DiscoLog::log() {

    if (_log == NULL) 
        _log = new DiscoLog();

    return _log;

}


void 
DiscoLog::entryNew(Priority priority,
                  NamedInterface * obj,
                  const string& funcName,
                  const string& cond) throw() {
    cerr << "'" << obj->name() << "'" << "." << funcName << "(): " << cond <<
        endl;
}

void 
DiscoLog::entryNew(Priority priority,
                  const string& funcName,
                  const string& cond) throw () {
    cerr << funcName << "(): " << cond << endl;        
}

void 
DiscoLog::entryNew(Priority priority,
                  const string& cond) throw() {
    cerr << cond << endl;        
}

} // namespace framework
