#include "LogImpl.h"

using std::cerr;
using std::endl;
    
Fwk::Ptr<Fwk::Log> log() { 
    return Fwk::LogImpl::log();
}

namespace Fwk {

Fwk::Ptr<Fwk::Log> LogImpl::log_ = NULL;

Fwk::Ptr<Fwk::Log> LogImpl::log() {

    if (log_ == NULL) 
        log_ = new LogImpl();

    return log_;

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

}
