#ifndef LOG_H
#define LOG_H

#include <string>

#include "NamedInterface.h"

using std::string;

namespace Fwk {

class Log : public NamedInterface {
public:

    enum Priority {
        null__,
        critical__,
        error__,
        warning__,
        status__,
        debug__
    };
    static const Priority null() { return null__; }
    static const Priority critical() { return critical__; }
    static const Priority error() { return error__; }
    static const Priority warning() { return warning__; }
    static const Priority status() { return status__; }
    static const Priority debug() { return debug__; }

    virtual void entryNew(Priority priority,
                          NamedInterface * obj,
                          const string& funcName,
                          const string& cond) throw() = 0;

    virtual void entryNew(Priority priority,
                          const string& funcName,
                          const string& cond) throw() = 0;

    virtual void entryNew(Priority priority,
                          const string& cond) throw() = 0;

protected:

    Log(const string& name) : NamedInterface(name) { }

};

extern Ptr<Log> log();

}

#endif
