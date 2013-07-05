#ifndef DISCO_VALUE_INERTIA
#define DISCO_VALUE_INERTIA

#include "Fundamental.h"
#include "Tensor.h"

namespace disco
{

// TODO maybe do not want to subclass from Tensor.
class Inertia : Tensor
{
public:

    // Constructors
    // ------------------------------------------------------------------------
    Inertia() {}
    Inertia(MomentOfInertia Ixx, MomentOfInertia Iyy, MomentOfInertia Izz)
    {
        // TODO check if the inputs are valid.
        _Ixx = Ixx;
        _Iyy = Iyy;
        _Izz = Izz;
    }
    Inertia(MomentOfInertia Ixx, MomentOfInertia Iyy, MomentOfInertia Izz,
            MomentOfInertia Ixy, MomentOfInertia Ixz, MomentOfInertia Iyz)
    {
        _Ixx = Ixx;
        _Iyy = Iyy;
        _Izz = Izz;
        _Ixy = Ixy;
        _Ixz = Ixz;
        _Iyz = Iyz;
    }

    // Accessors
    // ------------------------------------------------------------------------
    MomentOfInertia Ixx() const { return _Ixx; }
    MomentOfInertia Iyy() const { return _Iyy; }
    MomentOfInertia Izz() const { return _Izz; }

    MomentOfInertia Ixy() const { return _Ixy; }
    MomentOfInertia Ixz() const { return _Ixz; }
    MomentOfInertia Iyz() const { return _Iyz; }

private:

    // Moments of inertia
    // ------------------
    MomentOfInertia _Ixx;
    MomentOfInertia _Iyy;
    MomentOfInertia _Izz;

    // Products of inertia
    // -------------------
    MomentOfInertia _Ixy;
    MomentOfInertia _Ixz;
    MomentOfInertia _Iyz;
};

} // namespace disco

#endif
