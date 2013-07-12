#ifndef DISCO_MODELING_FRAME_H
#define DISCO_MODELING_FRAME_H

#include <disco/framework/NamedInterface.h>

namespace disco
{

class Frame : framework::NamedInterface
{
public:
    Point origin() const;
};

} // namespace disco

#endif
