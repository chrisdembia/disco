// Copyright (c) 1993-2007 David R. Cheriton, all rights reserved.
// Modified by Chris Dembia.

#ifndef FWK_NAMEDINTERFACE_H
#define FWK_NAMEDINTERFACE_H

#include <string>

#include "PtrInterface.h"

using std::string;

namespace fwk {

class NamedInterface : public PtrInterface<NamedInterface>
{
public:
	string name() const { return name_; }

protected:
	NamedInterface(const string& name) : name_(name) { }

private:
	string name_;
};

}

#endif
