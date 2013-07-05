#include "gtest/gtest.h"

#include <disco/framework/NamedInterface.h>

class InterfaceTest : public framework::NamedInterface
{
public:
    typedef framework::Ptr<InterfaceTest> Ptr;

    InterfaceTest() : NamedInterface("testName") {}
};

TEST(TestInterface, Ptr)
{
    InterfaceTest::Ptr it = new InterfaceTest();
    ASSERT_EQ("testName", it->name());
}

TEST(TestInterface, Notifiee)
{
    InterfaceTest::Ptr it = new InterfaceTest();
    // TODO InterfaceTest::Notifiee
    ASSERT_TRUE(false);
}
