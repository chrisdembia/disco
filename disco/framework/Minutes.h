// Copyright 2013 Christopher Dembia

#ifndef FRAMEWORK_MINUTES_H
#define FRAMEWORK_MINUTES_H

#include "Time.h"

namespace framework
{

class Seconds;

class Minutes : public Duration
{
public:

    const Minutes& operator=( const Minutes& v)
    {
        valueIs(v.value());
        return *this;
    }

    Minutes operator+( const Minutes& other)
    {
        return (this->value() + other.value_);
    }

    Minutes operator-( const Minutes& other)
    {
        return (this->value() - other.value_);
    }

    Minutes operator/( const Minutes& other)
    {
        return (value() / other.value());
    }

    Minutes(double value=0.0) : Duration(value) { }

    operator Seconds();
    operator Minutes() { return Minutes(this->value()); }
    // operator Microseconds() { return Microseconds(this->value() * 1000000.0); }

};

/*
class Hours : public Duration
{
public:

    const Hours& operator=( const Hours& v)
    {
        valueIs(v.value());
        return *this;
    }

    Hours operator+( const Hours& other)
    {
        return (this->value() + other.value_);
    }

    Hours operator-( const Hours& other)
    {
        return (this->value() - other.value_);
    }

    Hours operator/( const Hours& other)
    {
        return (value() / other.value());
    }

    Hours(double value=0.0) : Duration(value) { }

};

class Days : public Duration
{
public:

    Days(double value=0.0) : Duration(value) { }

    operator Hours() { return Hours(this->value() * 24.0); }

};
*/

} // namespace framework

#endif

