#ifndef DISCO_RIGIDBODY_H
#define DISCO_RIGIDBODY_H

#include <disco/framework/NamedInterface.h>

namespace disco
{

/**
 * @brief A rigid body.
 * */
class RigidBody : public NamedInterface
{
public:

    Mass mass();
    Inertia inertia();
    Position centerOfMass();
    Frame frame();

private:
};

} // namespace disco

#endif
/*

template<class T>
class NamedInterface : public PtrInterface<NamedInterface>
{
public:

    typedef framework::Ptr<T const> PtrConst;
    typedef framework::Ptr<T> Ptr;

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
*/
