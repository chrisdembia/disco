#ifndef DISCO_FORCE_H
#define DISCO_FORCE_H

#include "fwk/NamedInterface.h"

namespace disco
{

/**
 * @brief A force.
 * */
class Force : public NamedInterface
{
public:

    typedef framework::Ptr<Force> Ptr;

    /**
     * @brief Hello.
     * */
    value::Force value() const;

private:

    value::Force _value;
};

} // namespace disco
#endif
