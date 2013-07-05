// Copyright 2013 Christopher Dembia

#ifndef FRAMEWORK_SECONDS_H
#define FRAMEWORK_SECONDS_H

#include "Time.h"

/*
namespace framework
{

class Minutes;

class Seconds : public Duration
{
public:

    const Seconds& operator=( const Seconds& v)
    {
        valueIs(v.value());
        return *this;
    }

    Seconds operator+( const Seconds& other)
    {
        return (this->value() + other.value_);
    }

    Seconds operator-( const Seconds& other)
    {
        return (this->value() - other.value_);
    }

    Seconds operator/( const Seconds& other)
    {
        return (value() / other.value());
    }

    Seconds(double value=0.0) : Duration(value) { }

    operator Seconds() { return Seconds(this->value()); }
    operator Minutes();

    // operator Microseconds() { return Microseconds(this->value() * 1000000.0); }

};

} // namespace framework
*/

#endif
