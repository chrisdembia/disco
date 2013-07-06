#ifndef DISCO_VALUE_FUNDAMENTAL_H
#define DISCO_VALUE_FUNDAMENTAL_H

#include <boost/units/cmath.hpp>
#include <boost/units/systems/si.hpp>

using namespace boost::units;
using namespace boost::units::si;

namespace disco
{

typedef quantity<boost::units::si::time> Time;
typedef quantity<boost::units::si::mass> Mass;
typedef quantity<boost::units::si::moment_of_inertia> MomentOfInertia;

using boost::units::si::kilogram;
using boost::units::si::kilograms;

using boost::units::si::meter;
using boost::units::si::meters;

using boost::units::si::second;
using boost::units::si::seconds;

} // namespace disco

#endif
