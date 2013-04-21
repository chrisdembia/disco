#ifndef __NOMINAL_H__
#define __NOMINAL_H__

#include <sstream>
#include <string>
#include <iostream>

#include "LogImpl.h"

using namespace std;
using Fwk::LogImpl;
using Fwk::Log;

template<class UnitType, class RepType>
    class Nominal
{
public:
    Nominal(RepType v) : value_(v) {}
	
	bool operator==(const Nominal<UnitType, RepType>& v) const
	{ return value_ == v.value_; }
	
	bool operator!=(const Nominal<UnitType, RepType>& v) const
	{ return value_ != v.value_; }
	
	const Nominal<UnitType, RepType>& operator=(const Nominal<UnitType,
						    RepType>& v)
	{ value_ = v.value_; return *this; }
	
	RepType value() const
	{ return value_; }

    string str() const {
        ostringstream oss;
        oss << value();
        return oss.str();
    }

    //ostream& operator<<(ostream& os, const Nominal<UnitType, RepType>& n);
	
protected:
	RepType value_;
};

//ostream& 
//Nominal<class UnitType, class RepType>::operator<<(ostream& os, const Nominal<class UnitType, class RepType>& n) {
//    os << n.value();
//    return os;
//}

template<class UnitType, class RepType>
    class Ordinal : public Nominal<UnitType, RepType>
{
public:
    Ordinal(RepType v) : Nominal<UnitType, RepType>(v) {}
	
	bool operator<(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::value_ < v.value_; }
	
	bool operator<=(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::value_ <= v.value_; }
	
	bool operator>(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::value_ > v.value_; }

	bool operator>=(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::value_ >= v.value_; }
	
	Ordinal<UnitType, RepType> operator+(const Ordinal<UnitType,
					     RepType>& other)
	{ return (Nominal<UnitType, RepType>::value_ + other.value_); }
	
	Ordinal<UnitType, RepType> operator/(const Ordinal<UnitType,
					     RepType>& other)
	{ return (Nominal<UnitType, RepType>::value_ / other.value_); }
	
	const Ordinal<UnitType, RepType>& operator++()
	{ ++Nominal<UnitType, RepType>::value_; return *this; }

};

template<class UnitType, class RepType, int Default, int Min>
class LeftBounded : public Ordinal<UnitType, RepType> {
public:

    RepType min() const { return (RepType)Min; }

    const LeftBounded<UnitType, RepType, Default, Min>& operator=(
            const LeftBounded<UnitType, RepType, Default, Min>& v) {
        valueIs(v.value());
        return *this;
    }

    LeftBounded<UnitType, RepType, Default, Min> operator+(
            const LeftBounded<UnitType, RepType, Default, Min>& other) {
        return (this->value() + other.value_);
    }

    LeftBounded<UnitType, RepType, Default, Min> operator-(
            const LeftBounded<UnitType, RepType, Default, Min>& other) {
        return (this->value() - other.value_);
    }

    LeftBounded<UnitType, RepType, Default, Min> operator/(
            const LeftBounded<UnitType, RepType, Default, Min>& other) {
        return (Ordinal<UnitType, RepType>::value_ / other.value_);
    }

    LeftBounded(RepType value=(RepType)Default) :
            Ordinal<UnitType, RepType>(value) {
        valueIs((RepType)value);
    }

protected:

    void valueIs(RepType value) {
        if (value < min()) {
            ostringstream oss;
            oss << "Value " << value << " is not above " << min() << ".";
            LogImpl::log()->entryNew(Log::error(), "valueIs", oss.str());
            throw Fwk::RangeException(oss.str());
        }
        this->value_ = value;
    }
    
};

template<class UnitType, class RepType, int Default, int Min, int Max>
class DoubleBounded : public LeftBounded<UnitType, RepType, Default, Min> {
public:

    RepType max() const { return (RepType)Max; }

    const DoubleBounded<UnitType, RepType, Default, Min, Max>& operator=(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& v) {
        valueIs(v.value());
        return *this;
    }

    DoubleBounded<UnitType, RepType, Default, Min, Max> operator+(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& other) {
        return (this->value() + other.value_);
    }

    DoubleBounded<UnitType, RepType, Default, Min, Max> operator-(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& other) {
        return (this->value() - other.value_);
    }

    DoubleBounded<UnitType, RepType, Default, Min, Max> operator/(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& other) {
        return (Ordinal<UnitType, RepType>::value_ / other.value_);
    }

    DoubleBounded(RepType value=(RepType)Default) : 
            LeftBounded<UnitType, RepType, Default, Min>(value) {
        valueIs((RepType)value);
    }

protected:

    void valueIs(RepType value) {

        // Check lower bound first.
        LeftBounded<UnitType, RepType, Default, Min>::valueIs(value);

        if (value > max()) {
            ostringstream oss;
            oss << "Value " << value << " is not below " << max() << ".";
            LogImpl::log()->entryNew(Log::error(), "valueIs", oss.str());
            throw Fwk::RangeException(oss.str());
        }
        this->value_ = value;
    }
    
};

class Time { };

class Duration : public LeftBounded<Time, double, 0, 0> { 
public:

    const Duration& operator=( const Duration& v) {
        valueIs(v.value());
        return *this;
    }

    Duration operator+( const Duration& other) {
        return (this->value() + other.value_);
    }

    Duration operator-( const Duration& other) {
        return (this->value() - other.value_);
    }

    Duration operator/( const Duration& other) {
        return (value() / other.value());
    }

    Duration(double value=0) : LeftBounded<Time, double, 0, 0>(value) { }

//    operator Hours() { }

};

class Microseconds : public Duration {
public:

    const Microseconds& operator=( const Microseconds& v) {
        valueIs(v.value());
        return *this;
    }

    Microseconds operator+( const Microseconds& other) {
        return (this->value() + other.value_);
    }

    Microseconds operator-( const Microseconds& other) {
        return (this->value() - other.value_);
    }

    Microseconds operator/( const Microseconds& other) {
        return (value() / other.value());
    }

    Microseconds(double value=0.0) : Duration(value) { }

};

class Seconds : public Duration {
public:

    const Seconds& operator=( const Seconds& v) {
        valueIs(v.value());
        return *this;
    }

    Seconds operator+( const Seconds& other) {
        return (this->value() + other.value_);
    }

    Seconds operator-( const Seconds& other) {
        return (this->value() - other.value_);
    }

    Seconds operator/( const Seconds& other) {
        return (value() / other.value());
    }

    Seconds(double value=0.0) : Duration(value) { }

    operator Microseconds() { return Microseconds(this->value() * 1000000.0); }

};

class Hours : public Duration { 
public:

    const Hours& operator=( const Hours& v) {
        valueIs(v.value());
        return *this;
    }

    Hours operator+( const Hours& other) {
        return (this->value() + other.value_);
    }

    Hours operator-( const Hours& other) {
        return (this->value() - other.value_);
    }

    Hours operator/( const Hours& other) {
        return (value() / other.value());
    }

    Hours(double value=0.0) : Duration(value) { }

};

class Days : public Duration {
public:

    Days(double value=0.0) : Duration(value) { }

    operator Hours() { return Hours(this->value() * 24.0); }

};

class Rate { };

typedef LeftBounded<Rate, float, 0, 0> HoursPerSecond;

#endif // __NOMINAL_H__
