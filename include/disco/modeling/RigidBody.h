#ifndef DISCO_RIGIDBODY_H
#define DISCO_RIGIDBODY_H

#include "fwk/NamedInterface.h"

namespace disco
{

/**
 * @brief A rigid body.
 * */
class RigidBody : public NamedInterface
{
public:

    typedef fwk::Ptr<RigidBody const> PtrConst;
    typedef fwk::Ptr<RigidBody> Ptr;

    Mass mass();
    Inertia inertia();
    Position centerOfMass();

private:
};

} // namespace disco
#endif
