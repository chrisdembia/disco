#ifndef DISCO_MODELING_RIGIDBODY_H
#define DISCO_MODELING_RIGIDBODY_H

#include <disco/framework/NamedInterface.h>
#include <disco/value/Fundamental.h>
#include <disco/value/Inertia.h>

namespace disco
{

/**
 * @brief A rigid body.
 * */
class RigidBody : public framework::NamedInterface
{
public:

    typedef framework::Ptr<RigidBody const> PtrConst;
    typedef framework::Ptr<RigidBody> Ptr;

    // TODO use factory function.
    RigidBody(string name) : framework::NamedInterface(name) {}

    // mass
    // ----
    Mass mass() const { return _mass; }
    void massIs(Mass mass);

    // inertia
    // -------
    Inertia inertia() const { return _inertia; }
    void inertiaIs(Inertia inertia) { _inertia = inertia; }

    // Position centerOfMass();
    // Frame frame();

private:

    Mass _mass;
    Inertia _inertia;

};

void RigidBody::massIs(Mass mass)
{
    if (_mass != mass)
    {
        _mass = mass;

        // TODO tell notifiee's.
    }
}

/*
void RigidBody::inertiaIs(Inertia inertia)
{
    if (_inertia != inertia)
    {
        _inertia = inertia;

        // TODO notifiee's.
    }
}
*/

} // namespace disco

#endif
