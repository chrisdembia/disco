// Copyright 2013 Christopher Dembia

#ifndef FRAMEWORK_TIME_H
#define FRAMEWORK_TIME_H

#include "Nominal.h"

namespace framework
{

// typedef framework::LeftBounded<Unitless, double, 0, 0> NondimensionalDuration;

class Time {};

//class Microseconds;
//class Milliseconds;
//class Seconds;
//class Minutes;
//class Hours;
//class Days;

/*
typedef framework::LeftBounded<Time, double, 0, 0> Hours;

template<class ConversionFactors>
    class Duration : public Real<Time, double>
{
    Duration<SecondsConversionFactors> seconds()
    { value() * ConversionFactors.toSeconds() }

    Duration<MinutesConversionFactors> minutes()
    { value() * ConversionFactors.toMinutes() }

}

class SecondsConversionFactors
{
public:
    static const double toSeconds = 1.0;
    static const double toMinutes = 0.01666666666666666666666666666666666666667;
private:
    SecondsConversionFactors() {}
};

class MinutesConversionFactors
{
public:
    static const double toSeconds = 60.0;
    static const double toMinutes = 1.0;
private:
    MinutesConversionFactors() {}
}

typedef Duration<SecondsConversionFactors> Seconds;
typedef Duration<MinutesConversionFactors> Minutes;

*/
class Duration : public framework::LeftBounded<Time, double, 0, 0> {
public:

    const Duration& operator=( const Duration& v)
    {
        valueIs(v.value());
        return *this;
    }

    Duration operator+( const Duration& other)
    {
        return (this->value() + other.value());
    }

    Duration operator-( const Duration& other)
    {
        return (this->value() - other.value());
    }

    Duration operator/( const Duration& other)
    {
        // TODO not okay: need to convert to same units first.
        return (value() / other.value());
    }

    Duration(double value=0) : LeftBounded<Time, double, 0, 0>(value) { }

    //virtual operator Seconds() = 0;
    //virtual operator Minutes() = 0;
    //virtual operator Microseconds() = 0;
    //virtual operator Milliseconds() = 0;
    //virtual operator Hours() = 0;
    //virtual operator Days() = 0;

};
/*
class Microseconds : public Duration
{
public:

    const Microseconds& operator=( const Microseconds& v)
    {
        valueIs(v.value());
        return *this;
    }

    Microseconds operator+( const Microseconds& other)
    {
        return (this->value() + other.value_);
    }

    Microseconds operator-( const Microseconds& other)
    {
        return (this->value() - other.value_);
    }

    Microseconds operator/( const Microseconds& other)
    {
        return (value() / other.value());
    }

    Microseconds(double value=0.0) : Duration(value) { }

};

class Milliseconds : public Duration
{
public:

    const Milliseconds& operator=( const Milliseconds& v)
    {
        valueIs(v.value());
        return *this;
    }

    Milliseconds operator+( const Milliseconds& other)
    {
        return (this->value() + other.value_);
    }

    Milliseconds operator-( const Milliseconds& other)
    {
        return (this->value() - other.value_);
    }

    Milliseconds operator/( const Milliseconds& other)
    {
        return (value() / other.value());
    }

    Milliseconds(double value=0.0) : Duration(value) { }

};
*/


} // namespace framework

#endif
