#include <corecrt.h>
#include <lang/number/Integer.hpp>
#include <gtest/gtest.h>
#include <memory>
#include <stdint.h>
#include <vector>

using namespace Javalike::Lang;

TEST(Integer, IntegerValueCheck)
{
	Integer i(45);
    ASSERT_EQ(45, i.intValue());
}

TEST(Integer, BitCountCheck)
{
	struct TestStruct {
        int testValue;
        int Actual;
    };

    std::vector<TestStruct> testVec {
        {35, 3},
        {16, 1},
        {123412321, 16}
    };

    size_t index = 0;
    for(auto&& var : testVec) {
        const auto chk2 = Integer::bitCount(var.testValue);
        ASSERT_EQ(chk2,  var.Actual) << index;
        ++index;
    }
}

/**
 * @bug This method not working correctly
 * 
 */
TEST(Integer, StringbitDecodeCheck)
{
	struct TestStruct {
        std::string testValue;
        int Actual;
    };

    std::vector<TestStruct> testVec {
        {"0121", 81},
        // {"0x114", 276},
        // {"123412321", 16}
    };

    size_t index = 0;
    for(auto&& var : testVec) {
        auto chk = std::make_unique<Integer>(var.Actual);
        const auto chk2 = Integer::decode(var.testValue);
        ASSERT_EQ(chk2.intValue(),  chk->intValue()) << index;
        ++index;
    }
}