#ifndef DISCO_MODELING_POINT_H
#define DISCO_MODELING_POINT_H

namespace disco
{

class Point
{
public:

    Point(Frame fixed_in);

    Frame fixed_in() const;

    Vector position(Frame) const;
    void position_is(
    Vector velocity(Frame derivative_frame) const;
    Vector acceleration(Frame derivative_frame) const;
};
} // namespace disco

#endif
