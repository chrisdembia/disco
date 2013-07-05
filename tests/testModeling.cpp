#include "gtest/gtest.h"

#include <disco/modeling/modeling.h>

using namespace disco;

TEST(TestRigidBody, Construction)
{
    RigidBody rb("myFirstBody");

    // Default mass?
    ASSERT_EQ(rb.mass(), 0.0 * kilograms);

    rb.massIs(1.5 * kilograms);
    ASSERT_NE(rb.mass(), 0.0 * kilograms);
    ASSERT_EQ(rb.mass(), 1.5 * kilograms);
    // TODO ASSERT_EQ(rb.mass(), Mass(1500. * grams));
}


