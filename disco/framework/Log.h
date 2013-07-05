// Copyright(c) 1993-2006_2007, David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef FRAMEWORK_LOG_H
#define FRAMEWORK_LOG_H

#include <string>

#include "NamedInterface.h"

using std::string;

namespace framework
{

class Log : public NamedInterface<Log>
{
public:

    enum Priority
    {
        _null,
        _critical,
        _error,
        _warning,
        _status,
        _debug
    };
    static const Priority null() { return _null; }
    static const Priority critical() { return _critical; }
    static const Priority error() { return _error; }
    static const Priority warning() { return _warning; }
    static const Priority status() { return _status; }
    static const Priority debug() { return _debug; }

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

} // namespace framework

#endif
