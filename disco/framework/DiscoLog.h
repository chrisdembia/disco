// Copyright (C) 2013 Chris Dembia.

#ifndef DISCO_FRAMEWORK_DICSOLOG_H
#define DISCO_FRAMEWORK_DICSOLOG_H

#include "Log.h"
#include "Ptr.h"

#include <string>

using std::string;

framework::Ptr<framework::Log> log();

namespace framework {

/*!
 * Implementation of framework::Log for logging errors, etc.
 *
 * */
class DiscoLog : public framework::Log {
public:

    void entryNew(Priority priority,
                  NamedInterface * obj,
                  const string& funcName,
                  const string& cond) throw();

    void entryNew(Priority priority,
                  const string& funcName,
                  const string& cond) throw();

    void entryNew(Priority priority,
                  const string& cond) throw();

    static framework::Ptr<framework::Log> log();

protected:

    // TODO
    DiscoLog() : framework::Log("DiscoLog") { }

    static framework::Ptr<framework::Log> _log;

};

} // namespace framework

#endif
