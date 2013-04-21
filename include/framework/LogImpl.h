/*!
 * Implementation of Fwk::Log for logging errors, etc.
 *
 * */

#ifndef LOGIMPL_H
#define LOGIMPL_H

#include "Log.h"

#include <string>

using std::string;

Fwk::Ptr<Fwk::Log> log();

namespace Fwk {

class LogImpl : public Fwk::Log {
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

    static Fwk::Ptr<Fwk::Log> log();

protected:

    LogImpl() : Fwk::Log("ShippingLog") { }

    static Fwk::Ptr<Fwk::Log> log_;

};

}

#endif
