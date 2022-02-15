#include <cstddef>
#include <gtest/gtest.h>
#include <memory>
#include <stdint.h>
#include <util/Random.hpp>
#include <limits>

using namespace Javalike::Util;

TEST(Random, BooleanBoundCheck)
{
	var rd = std::make_unique<Random>();
	auto vChecker = [](bool x) -> bool { return x == 0 || x == 1; };

	// Test for  iteration;
	const uint8_t iterVal{255};
	for(int i = 0; i < iterVal; ++i)
	{
		ASSERT_TRUE(vChecker(rd->nextBoolean()));
	}
}

TEST(Random, RandomCheckBound0AndBetween1) {
    var rd = std::make_unique<Random>();
	auto vChecker = [](double x) -> bool { return x >= 0.0 && x <= 1.0; };

	// Test for 50 iteration;
	const uint8_t iterVal{255};
	for(int i = 0; i < iterVal; ++i) {
		ASSERT_TRUE(vChecker(rd->nextDouble()));
	}
}

TEST(Random, ByteArrayBoundCheck) {
    var rd = std::make_unique<Random>();
    uint8_t  byteMin = std::numeric_limits<uint8_t >::min();
    uint8_t byteMax = std::numeric_limits<uint8_t >::max();

	auto vChecker = [&](uint8_t x) -> bool { 
        return x >= byteMin && x <= byteMax; 
    };

	const uint8_t iterVal{255};

    std::vector<std::byte> byteArr(iterVal);
    rd->nextBytes(byteArr);
	// Test for 50 iteration;
	for(int i = 0; i < iterVal; ++i) {
		ASSERT_TRUE(vChecker(static_cast<uint8_t >(byteArr[i])));
	}
}