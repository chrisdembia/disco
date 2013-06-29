// Copyright (c) 1993-2007 David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef FRAMEWORK_NAMEDINTERFACE_H
#define FRAMEWORK_NAMEDINTERFACE_H

#include "Ptr.h"
#include "PtrInterface.h"
#include "BaseNotifiee.h"

using std::string;

namespace framework
{

class NamedInterface : public PtrInterface<NamedInterface>
{
public:
	string name() const { return _name; }

	class NotifieeConst : virtual public framework::RootNotifiee
    {
	public:
		typedef framework::Ptr<NotifieeConst const> PtrConst;
		typedef framework::Ptr<NotifieeConst> Ptr;
	};

	class Notifiee : virtual public NotifieeConst
    {
	public:
		typedef framework::Ptr<Notifiee const> PtrConst;
		typedef framework::Ptr<Notifiee> Ptr;
	};

protected:
	NamedInterface(const string& name) : _name(name) { }

private:
	string _name;
};

} // namespace framework

#endif
