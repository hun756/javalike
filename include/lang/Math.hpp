#ifndef JAVA_LANG_MATH_HPP
#define JAVA_LANG_MATH_HPP

#include <cmath>
#include <float.h>
#include <math.h>
#include <random>
#include <string>

// TODO : Fix parameter value type

namespace Javalike::Lang
{

	class MathException : public std::exception
	{
		using __STD_GLUTILITIES_EXCEPTION_DATA = std::string;

	public:
		/** Constructor (C strings).
		 *  @param message C-style string error message.
		 *                 The string contents are copied upon construction.
		 *                 Hence, responsibility for deleting the char* lies
		 *                 with the caller. 
		 */
		MathException(const char* message)
			: msg_(message)
		{ }

		/** Constructor (C++ STL strings).
		 *  @param message The error message.
		 */
		MathException(const std::string& message)
			: msg_(message)
		{ }

		/** Destructor.
		 * Virtual to allow for subclassing.
		 */
		virtual ~MathException() noexcept { }

		/** Returns a pointer to the (constant) error description.
		 *  @return A pointer to a const char*. The underlying memory
		 *          is in posession of the Exception object. Callers must
		 *          not attempt to free the memory.
		 */
		virtual const char* what() const noexcept
		{
			return msg_.c_str();
		}

	protected:
		/** Error message.
     	*/
		__STD_GLUTILITIES_EXCEPTION_DATA msg_;
	};

	template <typename T>
	struct MathBase
	{
		static T _addExact(T val1, T val2)
		{
			return val1 + val2;
		}

		static T Max(T a, T b)
		{
			return (a > b ? a : b);
		}

		template <class... a>
		static T Max(T x, a... z)
		{
			T k = Max(z...);
			return (x > k ? x : k);
		}

		static T Min(T a, T b)
		{
			return (a < b ? a : b);
		}

		template <class... a>
		static T Min(T x, a... z)
		{
			T k = Min(z...);
			return (x < k ? x : k);
		}

		using Numeric = T;
		template <typename Generator = std::default_random_engine>
		static Numeric random(Numeric from, Numeric to)
		{
			thread_local static Generator gen(std::random_device{}());

			using dist_type =
				typename std::conditional<std::is_integral<Numeric>::value,
										  std::uniform_int_distribution<Numeric>,
										  std::uniform_real_distribution<Numeric>>::type;

			thread_local static dist_type dist;

			return dist(gen, typename dist_type::param_type{from, to});
		}
	};

	class Math
	{
	public:
		///< static member fucitons
		static constexpr double PI = 3.141592653589793;
		static constexpr double E = 2.718281828459045;

		///< methods
		//Returns the absolute value of a double value.
		static double abs(double a)
		{
			return std::abs(a);
		}
		//Returns the absolute value of a float value.
		static float abs(float a)
		{
			return std::abs(a);
		}
		// Returns the absolute value of an int value.
		static int abs(int a)
		{
			return std::abs(a);
		}
		//Returns the absolute value of a long value.
		static long abs(long a)
		{
			return std::abs(a);
		}
		// Returns the arc cosine of a value; the returned angle is in the range 0.0 through pi.
		static double acos(double a)
		{
			return std::acos(a);
		}
		// Returns the sum of its arguments, throwing an exception if the result overflows an int.
		static int addExact(int x, int y)
		{
			return MathBase<int>::_addExact(x, y);
		}
		// Returns the sum of its arguments, throwing an exception if the result overflows a long.
		static long addExact(long x, long y)
		{
			return MathBase<int>::_addExact(x, y);
		}
		// Returns the arc sine of a value; the returned angle is in the range -pi/2 through pi/2.
		static double asin(double a)
		{
			return std::asin(a);
		}
		//Returns the arc tangent of a value; the returned angle is in the range -pi/2 through pi/2.
		static double atan(double a)
		{
			return std::atan(a);
		}
		// Returns the angle theta from the conversion of rectangular coordinates (x, y) to polar coordinates (r, theta).
		static double atan2(double y, double x)
		{
			return std::atan2(x, y);
		}
		// Returns the cube root of a double value.
		static double cbrt(double a)
		{
			return std::cbrt(a);
		}
		// Returns the smallest (closest to negative infinity) double value that is greater than or equal to the argument and is equal to a mathematical integer.
		static double ceil(double a)
		{
			return std::ceil(a);
		}
		// Returns the first floating-point argument with the sign of the second floating-point argument.
		static double copySign(double magnitude, double sign)
		{
			return std::copysign(magnitude, sign);
		}
		// Returns the first floating-point argument with the sign of the second floating-point argument.
		static float copySign(float magnitude, float sign)
		{
			return std::copysign(magnitude, sign);
		}
		// Returns the trigonometric cosine of an angle.
		static double cos(double a)
		{
			return std::cos(a);
		}
		// Returns the hyperbolic cosine of a double value.
		static double cosh(double x)
		{
			return std::cosh(x);
		}
		// Returns the argument decremented by one, throwing an exception if the result overflows an int.
		static int decrementExact(int a)
		{
			return a - 1;
		}
		// Returns the argument decremented by one, throwing an exception if the result overflows a long.
		static long decrementExact(long a)
		{
			return a - 1;
		}
		// Returns Euler's number e raised to the power of a double value.
		static double exp(double a)
		{
			return std::exp(a);
		}
		// Returns ex -1.
		static double expm1(double x)
		{
			return std::expm1(x);
		}
		// Returns the largest (closest to positive infinity) double value that is less than or equal to the argument and is equal to a mathematical integer.
		static double floor(double a)
		{
			return std::floor(a);
		}
		// Returns the largest (closest to positive infinity) int value that is less than or equal to the algebraic quotient.
		static int floorDiv(int x, int y)
		{
			return x / y;
		}
		// Returns the largest (closest to positive infinity) long value that is less than or equal to the algebraic quotient.
		static long floorDiv(long x, long y)
		{
			return x / y;
		}
		// Returns the floor modulus of the int arguments.
		static int floorMod(int x, int y)
		{
			return ((x % y) + y) % y;
		}
		// Returns the floor modulus of the long arguments.
		static long floorMod(long x, long y)
		{
			return ((x % y) + y) % y;
		}
		// Returns the unbiased exponent used in the representation of a double.
		static int getExponent(double d)
		{
			return std::round(std::log2(d));
		}
		// Returns the unbiased exponent used in the representation of a float.
		static int getExponent(float f)
		{
			return std::round(std::log2(f));
		}
		// Returns sqrt(x2 +y2) without intermediate overflow or underflow.
		static double hypot(double x, double y)
		{
			return std::hypot(x, y);
		}

		// Computes the remainder operation on two arguments as prescribed by the IEEE 754 standard.
		static double IEEEremainder(double f1, double f2)
		{
			// Todo : Add java NaN support

			throw MathException("The NaN object is currently not supported.");
		}

		// Returns the argument incremented by one, throwing an exception if the result overflows an int.
		static int incrementExact(int a)
		{
			return a + 1;
		}
		//Returns the argument incremented by one, throwing an exception if the result overflows a long.
		static long incrementExact(long a)
		{
			return a + 1;
		}
		//Returns the natural logarithm (base e) of a double value.
		static double log(double a)
		{
			return std::log(a);
		}
		//Returns the base 10 logarithm of a double value.
		static double log10(double a)
		{
			return std::log(a);
		}
		//Returns the natural logarithm of the sum of the argument and 1.
		static double log1p(double x)
		{
			return std::log1p(x);
		}
		//Returns the greater of two double values.
		static double max(double a, double b)
		{
			return MathBase<double>::Max(a, b);
		}
		// Returns the greater of two float values.
		static float max(float a, float b)
		{
			return MathBase<float>::Max(a, b);
		}
		// Returns the greater of two int values.
		static int max(int a, int b)
		{
			return MathBase<int>::Max(a, b);
		}
		// Returns the greater of two long values.
		static long max(long a, long b)
		{
			return MathBase<long>::Max(a, b);
		}
		// Returns the smaller of two double values.
		static double min(double a, double b)
		{
			return MathBase<double>::Min(a, b);
		}
		// Returns the smaller of two float values.
		static float min(float a, float b)
		{
			return MathBase<float>::Min(a, b);
		}
		// Returns the smaller of two int values.
		static int min(int a, int b)
		{
			return MathBase<int>::Min(a, b);
		}
		// Returns the smaller of two long values.
		static long min(long a, long b)
		{
			return MathBase<long>::Min(a, b);
		}
		// Returns the product of the arguments, throwing an exception if the result overflows an int.
		static int multiplyExact(int x, int y)
		{
			return x * y;
		}
		// Returns the product of the arguments, throwing an exception if the result overflows a long.
		static long multiplyExact(long x, long y)
		{
			return x * y;
		}
		// Returns the negation of the argument, throwing an exception if the result overflows an int.
		static int negateExact(int a)
		{
			return -1 * a;
		}
		// Returns the negation of the argument, throwing an exception if the result overflows a long.
		static long negateExact(long a)
		{
			return -1 * a;
		}
		// Returns the floating-point number adjacent to the first argument in the direction of the second argument.
		static double nextAfter(double start, double direction)
		{
			return std::nextafter(start, direction);
		}
		// Returns the floating-point number adjacent to the first argument in the direction of the second argument.
		static float nextAfter(float start, double direction)
		{
			return std::nextafter(start, direction);
		}
		// Returns the floating-point value adjacent to d in the direction of negative infinity.
		static double nextDown(double d)
		{
			// Todo Implement function
			return 0.0;
		}
		// Returns the floating-point value adjacent to f in the direction of negative infinity.
		static float nextDown(float f)
		{
			// Todo Implement function
			return 0.0;
		}
		// Returns the floating-point value adjacent to d in the direction of positive infinity.
		static double nextUp(double d)
		{
			// Todo Implement function
			return 0.0;
		}
		// Returns the floating-point value adjacent to f in the direction of positive infinity.
		static float nextUp(float f)
		{
			// Todo Implement function
			return 0.0;
		}
		// Returns the value of the first argument raised to the power of the second argument.
		static double pow(double a, double b)
		{
			return std::pow(a, b);
		}
		// Returns a double value with a positive sign, greater than or equal to 0.0 and less than 1.0.
		static double random()
		{
			return MathBase<double>::random(0.0, 1.0);
		}
		// Returns the double value that is closest in value to the argument and is equal to a mathematical integer.
		static double rint(double a)
		{
			return std::rint(a);
		}
		// Returns the closest long to the argument, with ties rounding to positive infinity.
		static long round(double a)
		{
			return std::round(a);
		}
		// Returns the closest int to the argument, with ties rounding to positive infinity.
		static int round(float a)
		{
			return std::round(a);
		}

		// Returns d × 2scaleFactor rounded as if performed by a single correctly rounded
		// floating-point multiply to a member of the double value set.
		static double scalb(double d, int scaleFactor)
		{
			return std::scalbn(d, scaleFactor);
		}

		// Returns f × 2scaleFactor rounded as if performed by a single correctly rounded
		// floating-point multiply to a member of the float value set.
		static float scalb(float f, int scaleFactor)
		{
			return std::scalbnf(f, scaleFactor);
		}
		// Returns the signum function of the argument; zero if the argument is zero, 1.0
		// if the argument is greater than zero, -1.0 if the argument is less than zero.
		static double signum(double d)
		{
			// TODO : Fix double comperation
			return (d == 0.0) ? 0.0 : (d > 0) ? 1.0 : -1.0;
		}
		// Returns the signum function of the argument; zero if the argument is zero, 1.0f
		// if the argument is greater than zero, -1.0f if the argument is less than zero.
		static float signum(float f)
		{
			// TODO : Fix float comperation
			return (f == 0.0) ? 0.0 : (f > 0) ? 1.0 : -1.0;
		}
		// Returns the trigonometric sine of an angle.
		static double sin(double a)
		{
			return std::sin(a);
		}
		// Returns the hyperbolic sine of a double value.
		static double sinh(double x)
		{
			return std::sinh(x);
		}
		// Returns the correctly rounded positive square root of a double value.
		static double sqrt(double a)
		{
			return std::sqrt(a);
		}
		// Returns the difference of the arguments, throwing an exception if the result overflows an int.
		static int subtractExact(int x, int y)
		{
			return x - y;
		}
		// Returns the difference of the arguments, throwing an exception if the result overflows a long.
		static long subtractExact(long x, long y)
		{
			return x - y;
		}
		// Returns the trigonometric tangent of an angle.
		static double tan(double a)
		{
			return std::tan(a);
		}
		// Returns the hyperbolic tangent of a double value.
		static double tanh(double x)
		{
			return std::tanh(x);
		}
		// Converts an angle measured in radians to an approximately equivalent angle measured in degrees.
		static double toDegrees(double angrad) {
			// TODO implements duction
			return 0.0;
		 }
		// Returns the value of the long argument; throwing an exception if the value overflows an int.
		static int toIntExact(long value) {
			// TODO implements duction
			return 0.0;
		 }
		// Converts an angle measured in degrees to an approximately equivalent angle measured in radians.
		static double toRadians(double angdeg) { 
			// TODO implements duction
			return 0.0;
		}
		// Returns the size of an ulp of the argument.
		static double ulp(double d) { 
			// TODO implements duction
			return 0.0;
		}
		// Returns the size of an ulp of the argument.
		static float ulp(float f) { 
			// TODO implements duction
			return 0.0;
		}
	};
} // namespace JavaLike::Lang

#endif /* End of include guard : JAVA_LANG_MATH_HPP */