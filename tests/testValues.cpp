#include "gtest/gtest.h"

#include <framework/Time.h>
#include <framework/Seconds.h>
#include <framework/Minutes.h>

using namespace framework;

TEST(TestDuration, Construction)
{
    // Default argument.
    Seconds durationA;
    ASSERT_EQ(0.0, durationA.value());

    // Construction.
    Seconds durationB(3.5);
    Seconds durationC(4.2);

    // Copy constructor.
    Seconds durationD = durationB;
    ASSERT_EQ(3.5, durationD.value());
}

/*
TEST(TestDuration, Operations)
{
    // Operations.
    ASSERT_EQ(7.7, (durationA + durationB).value());
    ASSERT_EQ(0.7, (durationB - durationA).value());
}

TEST(TestDuration, String)
{
    // TODO conversion to string.
    ASSERT_TRUE(false);
}

TEST(TestDuration, UnitConversion)
{
    Hours time(2.0);
    ASSERT_EQ(2.0 / 24.0, Days(time).value());
    ASSERT_EQ(2.0, time.value());
    ASSERT_EQ(120.0, Minutes(time).value());
    ASSERT_EQ(120.0 * 60.0, Seconds(time).value());
    ASSERT_EQ(120.0 * 60.0 * 1000.0, Milliseconds(time).value());
    ASSERT_EQ(120.0 * 60.0 * 1000.0 * 1000.0, Microseconds(time).value());


}
*/

/* TODO
TEST(TestValues, Length)
{
    ASSERT_TRUE(false);

    Meters myFirstLength();
    Meters mySecondLength(1.53);

    Centimeters myThirdLength(153.0);

    // Test equality between mySecondLength and myThirdLength.
}
*/

