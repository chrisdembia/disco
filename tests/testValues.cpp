#include "gtest/gtest.h"

#include <disco/value/value.h>

using namespace disco;

TEST(TestTime, Construction)
{
    Time myFirstTime = 1.5 * second;
    Time mySecondTime = 2.5 * seconds;
}

TEST(TestTime, Addition)
{
    Time myFirstTime = 1.5 * second;
    Time mySecondTime = 2.5 * seconds;
    Time myThirdTime = myFirstTime + mySecondTime;

    ASSERT_EQ(4.0 * seconds, myThirdTime);
}

TEST(TestInertia, Construction)
{
    MomentOfInertia Ixx = 1.2 * moment_of_inertia();
    MomentOfInertia Iyy = 10.3 * moment_of_inertia();
    MomentOfInertia Izz = 11.5 * moment_of_inertia();
    Inertia I(Ixx, Iyy, Izz);

    ASSERT_EQ(I.Ixx(), Ixx);
    ASSERT_EQ(I.Iyy(), Iyy);
    ASSERT_EQ(I.Izz(), Izz);
    ASSERT_EQ(I.Ixy(), 0.0 * moment_of_inertia());
    ASSERT_EQ(I.Ixz(), 0.0 * moment_of_inertia());
    ASSERT_EQ(I.Iyz(), 0.0 * moment_of_inertia());

    // TODO other constructors.

}

/*
TEST(TestTime, UnitConversion)
{
    // TODO
}
*/

// TODO dimensionless.

/*
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
*/

// TODO write to string / output stream.
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

