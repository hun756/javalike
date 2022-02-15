#ifndef JAVALIKE_UTIL_RANDOM_HPP
#define JAVALIKE_UTIL_RANDOM_HPP

#include <functional>
#include <iterator>
#include <limits>
#include <random>

#include <algorithm>

#include <helpers/JavalikeType.hpp>

namespace Javalike::Util
{
	class DoubleStream;
	class IntStream;
	class LongStream;

	/**
	 * @brief 
	 * 
	 * @tparam Numeric 
	 * @tparam Generator 
	 */
	template <typename Numeric, typename Generator>
	struct RandomBaseHelper
	{
		using dataType = Numeric;
		using distType = 
			typename std::conditional<
				std::is_integral<Numeric>::value,
				std::uniform_int_distribution<Numeric>,
				std::uniform_real_distribution<Numeric>
			>::type;
		using randEngine = Generator;
	};

	/**
	 * @brief 
	 * 
	 * @tparam Numeric 
	 * @tparam Generator 
	 */
	template <typename Numeric, typename Generator>
	struct ComputeRand
	{
		using helper = RandomBaseHelper<Numeric, Generator>;
		static constexpr typename helper::dataType _gen(
			typename helper::dataType a,
			typename helper::dataType b
		) 
		{
			auto gen = std::bind(
				typename helper::distType(a, b),
				typename helper::randEngine(std::random_device{}())
			);
			return gen();
		}
	};

	// namespace RandomHelper
	// {

	// }

	class Random
	{
	public:
		// Creates a new random number generator.
		Random() = default;

		// Creates a new random number generator using a single long seed.
		Random(unsigned long _seed)
			: seed(_seed)
		{
			en.seed(seed);
		}

		// Returns an effectively unlimited stream of pseudorandom double values,
		// each between zero (inclusive) and one (exclusive).
		//DoubleStream doubles() { }

		// Returns an effectively unlimited stream of pseudorandom double values,
		// each conforming to the given origin (inclusive) and bound (exclusive).
		//DoubleStream doubles(double randomNumberOrigin, double randomNumberBound) { }

		// Returns a stream producing the given streamSize number of pseudorandom double values,
		// each between zero (inclusive) and one (exclusive).
		//DoubleStream doubles(long streamSize) { }

		// Returns a stream producing the given streamSize number of pseudorandom double values,
		// each conforming to the given origin (inclusive) and bound (exclusive).
		//DoubleStream doubles(long streamSize, double randomNumberOrigin, double randomNumberBound)
		//{ }

		// Returns an effectively unlimited stream of pseudorandom int values.
		//IntStream ints() { }

		// Returns an effectively unlimited stream of pseudorandom int values,
		// each conforming to the given origin (inclusive) and bound (exclusive).
		//IntStream ints(int randomNumberOrigin, int randomNumberBound) { }

		// Returns a stream producing the given streamSize number of pseudorandom int values.
		//IntStream ints(long streamSize) { }

		// Returns a stream producing the given streamSize number of pseudorandom int values,
		// each conforming to the given origin (inclusive) and bound (exclusive).
		//IntStream ints(long streamSize, int randomNumberOrigin, int randomNumberBound) { }

		// Returns an effectively unlimited stream of pseudorandom long values.
		//LongStream longs() { }

		// Returns a stream producing the given streamSize number of pseudorandom long values.
		//LongStream longs(long streamSize) { }

		// Returns an effectively unlimited stream of pseudorandom long values,
		// each conforming to the given origin (inclusive) and bound (exclusive).
		//LongStream longs(long randomNumberOrigin, long randomNumberBound) { }

		// Returns a stream producing the given streamSize number of pseudorandom long,
		// each conforming to the given origin (inclusive) and bound (exclusive).
		//LongStream longs(long streamSize, long randomNumberOrigin, long randomNumberBound) { }

		// Generates the next pseudorandom number.
	protected:
		int next(int bits)
		{
			return this->nextInt(bits);
		}

	public:
		// Returns the next pseudorandom, uniformly distributed boolean value from this random number generator's sequence.
		bool nextBoolean()
		{
			return ComputeRand<int, decltype(en)>::_gen(0, 1);
		}
		// Generates random bytes and places them into a user-supplied byte array.
		void nextBytes(JavalikeType::Array<std::byte>& bytes)
		{
			std::generate(std::begin(bytes), std::end(bytes), []() {
				return static_cast<std::byte> (
					ComputeRand<uint8_t, decltype(this->en)>::_gen (
						std::numeric_limits<uint8_t>::min(), 
						std::numeric_limits<uint8_t>::max()
					)
				);
			});
		}
		// Returns the next pseudorandom, uniformly distributed double value between 0.0 and 1.0 from this random number generator's sequence.
		double nextDouble()
		{
			return ComputeRand<double, decltype(en)>::_gen(0.0, 1.0);
		}
		// Returns the next pseudorandom, uniformly distributed float value between 0.0 and 1.0 from this random number generator's sequence.
		float nextFloat()
		{
			return ComputeRand<float, decltype(en)>::_gen(0.0f, 1.0f);
		}
		// Returns the next pseudorandom, Gaussian ("normally") distributed double value with
		// mean 0.0 and standard deviation 1.0 from this random number generator's sequence.
		double nextGaussian()
		{
			// TODO : Use with normal distrubition < std::normal_distribution >
			return std::bind (
				std::normal_distribution<>(0.0, 1.0),
				std::default_random_engine(
					std::random_device{}()
				)
			)();
		}
		// Returns the next pseudorandom, uniformly distributed int value from this random number generator's sequence.
		int nextInt()
		{
			return ComputeRand<int, decltype(en)>::_gen(
				std::numeric_limits<int>::min(),
				std::numeric_limits<int>::max()
			);
		}
		// Returns a pseudorandom, uniformly distributed int value between 0 (inclusive) and the specified value (exclusive),
		//  drawn from this random number generator's sequence.
		int nextInt(int bound)
		{
			return ComputeRand<int, decltype(en)>::_gen(0, bound);
		}
		// Returns the next pseudorandom, uniformly distributed long value from this random number generator's sequence.
		long nextLong()
		{
			return ComputeRand<long, decltype(en)>::_gen(
				std::numeric_limits<long>::min(),
				std::numeric_limits<long>::max()
			);
		}
		// Sets the seed of this random number generator using a single long seed.
		void setSeed(unsigned long seed)
		{
			this->seed = seed;
		}

	private:
		static std::default_random_engine en;
		unsigned long seed;
	};
} // namespace Javalike::Util

#endif /* End of include guard : JAVALIKE_UTIL_RANDOM_HPP */