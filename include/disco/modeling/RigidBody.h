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

    /**
     * @brief Hello.
     * */
    void testing();

private:
};

} // namespace disco
#endif
