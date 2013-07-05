// Copyright (c) 1993-2007 David R. Cheriton, all rights reserved.
// Modified by Chris Dembia (2013).

#ifndef FRAMEWORK_NOMINAL_H
#define FRAMEWORK_NOMINAL_H

#include "DiscoLog.h"
#include "Exception.h"

#include <sstream>
#include <string>
#include <iostream>

using std::ostringstream;
using framework::DiscoLog;
using framework::Log;

namespace framework
{

/**
 * @brief Identifiers that do not have an order to them (e.g., serial numbers).
 * */
template<class UnitType, class RepType>
    class Nominal
{
public:
    Nominal(RepType v) : _value(v) {}
	
	bool operator==(const Nominal<UnitType, RepType>& v) const
	{ return _value == v._value; }
	
	bool operator!=(const Nominal<UnitType, RepType>& v) const
	{ return _value != v._value; }
	
	const Nominal<UnitType, RepType>& operator=(const Nominal<UnitType,
						    RepType>& v)
	{ _value = v._value; return *this; }
	
	RepType value() const
	{ return _value; }

    std::string string() const
    {
        ostringstream oss;
        oss << value();
        return oss.str();
    }

    // TODO ostream& operator<<(ostream& os, const Nominal<UnitType, RepType>& n);
	
protected:
	RepType _value;
};

// TODO
//ostream& 
//Nominal<class UnitType, class RepType>::operator<<(ostream& os, const Nominal<class UnitType, class RepType>& n) {
//    os << n.value();
//    return os;
//}

/**
 * @brief Identifiers that have an order; e.g., a count of rigid bodies.
 *
 * A count of rigid bodies may be made using:
 * typedef Ordinal<RigidBody, int> RigidBodyCount;
 * */
template<class UnitType, class RepType>
    class Ordinal : public Nominal<UnitType, RepType>
{
public:
    Ordinal(RepType v) : Nominal<UnitType, RepType>(v) {}
	
	bool operator<(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::_value < v._value; }
	
	bool operator<=(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::_value <= v._value; }
	
	bool operator>(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::_value > v._value; }

	bool operator>=(const Ordinal<UnitType, RepType>& v) const
	{ return Nominal<UnitType, RepType>::_value >= v._value; }
	
	Ordinal<UnitType, RepType> operator+(const Ordinal<UnitType,
					     RepType>& other)
	{ return (Nominal<UnitType, RepType>::_value + other._value); }
	
	Ordinal<UnitType, RepType> operator/(const Ordinal<UnitType,
					     RepType>& other)
	{ return (Nominal<UnitType, RepType>::_value / other._value); }
	
	const Ordinal<UnitType, RepType>& operator++()
	{ ++Nominal<UnitType, RepType>::_value; return *this; }

};

template<class UnitType, class RepType, int Default, int Min>
class LeftBounded : public Ordinal<UnitType, RepType>
{
public:

    RepType min() const { return (RepType)Min; }

    const LeftBounded<UnitType, RepType, Default, Min>& operator=(
            const LeftBounded<UnitType, RepType, Default, Min>& v)
    {
        valueIs(v.value());
        return *this;
    }

    LeftBounded<UnitType, RepType, Default, Min> operator+(
            const LeftBounded<UnitType, RepType, Default, Min>& other)
    {
        return (this->value() + other._value);
    }

    LeftBounded<UnitType, RepType, Default, Min> operator-(
            const LeftBounded<UnitType, RepType, Default, Min>& other)
    {
        return (this->value() - other._value);
    }

    LeftBounded<UnitType, RepType, Default, Min> operator/(
            const LeftBounded<UnitType, RepType, Default, Min>& other)
    {
        return (Ordinal<UnitType, RepType>::_value / other._value);
    }

    LeftBounded(RepType value=(RepType)Default) :
            Ordinal<UnitType, RepType>(value)
    {
        valueIs((RepType)value);
    }

protected:

    void valueIs(RepType value)
    {
        if (value < min())
        {
            ostringstream oss;
            oss << "Value " << value << " is not above " << min() << ".";
            DiscoLog::log()->entryNew(Log::error(), "valueIs", oss.str());
            throw framework::RangeException(oss.str());
        }
        this->_value = value;
    }
    
};

template<class UnitType, class RepType, int Default, int Min, int Max>
class DoubleBounded : public LeftBounded<UnitType, RepType, Default, Min>
{
public:

    RepType max() const { return (RepType)Max; }

    const DoubleBounded<UnitType, RepType, Default, Min, Max>& operator=(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& v)
    {
        valueIs(v.value());
        return *this;
    }

    DoubleBounded<UnitType, RepType, Default, Min, Max> operator+(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& other)
    {
        return (this->value() + other._value);
    }

    DoubleBounded<UnitType, RepType, Default, Min, Max> operator-(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& other)
    {
        return (this->value() - other._value);
    }

    DoubleBounded<UnitType, RepType, Default, Min, Max> operator/(
            const DoubleBounded<UnitType, RepType, Default, Min, Max>& other)
    {
        return (Ordinal<UnitType, RepType>::_value / other._value);
    }

    DoubleBounded(RepType value=(RepType)Default) : 
            LeftBounded<UnitType, RepType, Default, Min>(value)
    {
        valueIs((RepType)value);
    }

protected:

    void valueIs(RepType value)
    {

        // Check lower bound first.
        LeftBounded<UnitType, RepType, Default, Min>::valueIs(value);

        if (value > max())
        {
            ostringstream oss;
            oss << "Value " << value << " is not below " << max() << ".";
            DiscoLog::log()->entryNew(Log::error(), "valueIs", oss.str());
            throw framework::RangeException(oss.str());
        }
        this->_value = value;
    }

};

} // end namespace

#endif
