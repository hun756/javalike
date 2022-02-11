#include <Math.hpp>
#include <gtest/gtest.h>
#include <stdint.h>

using namespace Javalike::Lang;

TEST(Math, MathRandomCheckBound0AndBetween1)
{
	auto vChecker = [](double x) -> bool { return x >= 0.0 && x <= 1.0; };

	// Test for 50 iteration;
	const uint8_t iterVal{50};
	for(int i = 0; i < iterVal; ++i)
	{
		ASSERT_TRUE(vChecker(Math::random()));
	}
}
