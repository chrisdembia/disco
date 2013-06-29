// Copyright (c) 1993-2007 David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef FRAMEWORK_NAMEDINTERFACE_H
#define FRAMEWORK_NAMEDINTERFACE_H

#include "framework/PtrInterface.h"
#include "framework/BaseNotifiee.h"

using std::string;

namespace framework {

class NamedInterface : public PtrInterface<NamedInterface>
{
public:
	string name() const { return name_; }

	class NotifieeConst : virtual public RootNotifiee {
	public:
		typedef framework::Ptr<NotifieeConst const> PtrConst;
		typedef framework::Ptr<NotifieeConst> Ptr;
	};

	class Notifiee : virtual public NotifieeConst {
	public:
		typedef framework::Ptr<Notifiee const> PtrConst;
		typedef framework::Ptr<Notifiee> Ptr;
	};

protected:
	NamedInterface(const string& name) : name_(name) { }

private:
	string name_;
};

} // namespace framework

#endif
