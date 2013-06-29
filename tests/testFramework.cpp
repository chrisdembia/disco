#include "gtest/gtest.h"

class InterfaceTest : public NamedInterface
{
    typedef framework::Ptr<InterfaceTest> Ptr;
};

TEST(TestInterface, Ptr)
{
    InterfaceTest::Ptr it = new InterfaceTest();
}
