/**
 *  @file 
 *      Integer.hpp
 *  @author 
 *      Mehmet Ekemen (ekemenms@gmail.com)
 *  @brief 
 *      
 *  @version 0.1
 *  @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef JAVA_LANG_INTEGER_HPP
#define JAVA_LANG_INTEGER_HPP

#include <bitset>
#include <limits>
#include <number/number.hpp>
#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>

typedef std::string String;
typedef std::byte byte;

namespace Javalike::Lang
{
	namespace Helper
	{
		template <typename T>
		//static inline  // static if you want to compile with -mpopcnt in one compilation unit but not others
		inline typename std::enable_if<std::is_integral<T>::value, unsigned>::type popcount(T x)
		{
			static_assert(std::numeric_limits<T>::radix == 2, "non-binary type");

			// sizeof(x)*CHAR_BIT
			constexpr int bitwidth =
				std::numeric_limits<T>::digits + std::numeric_limits<T>::is_signed;
			// std::bitset constructor was only unsigned long before C++11.  Beware if porting to C++03
			static_assert(bitwidth <= std::numeric_limits<unsigned long long>::digits,
						  "arg too wide for std::bitset() constructor");
			// probably not needed, bitset width chops after sign-extension
			typedef typename std::make_unsigned<T>::type UT;

			std::bitset<bitwidth> bs(static_cast<UT>(x));
			return bs.count();
		}

		/**
         * @brief 
         * 
         * @param a 
         * @return int 
         * 
         * @bug
         * 
         * \failed
         */
		inline int BinaryStringToDecimal(String a)
		{
			enum class BaseType
			{
				Base8,
				Base16,
				Base16Signed
			} bs;

			bool flag = true;
			String resStr;

			if(a[0] == '-')
			{
				flag = false;
				resStr = a.substr(1, a.length());
			}

			if(resStr[0] == '0' && resStr[1] == 'x')
			{
				resStr.substr(2, resStr.size());
				(!flag) ? bs = BaseType::Base16Signed : bs = BaseType::Base16;
			}
			else
			{
				resStr.substr(1, resStr.size());
				bs = BaseType::Base8;
			}

			if(bs == BaseType::Base8)
			{
				int i{std::stoi(resStr, 0, 8)};

				return (!flag) ? i : -1 * i;
			}
			else if(bs == BaseType::Base16 || bs == BaseType::Base16Signed)
			{
				unsigned int i;
				std::stringstream ss;
				ss << std::hex << resStr;
				ss >> i;

				if(bs == BaseType::Base16Signed)
				{
					return -1 * 2;
				}
				return i;
			}
			else
			{
				throw std::domain_error("Unkown Base Type..!");
			}
			throw std::domain_error("Unkown Base Type..!");
		}
	} // namespace Helper

	class Integer
	{
	public:
		// fields
		// The number of bytes used to represent a int value in two's complement binary form.
		static int BYTES;
		// A constant holding the maximum value an int can have, 231-1.
		static constexpr int MAX_VALUE = std::numeric_limits<int>::max();
		// A constant holding the minimum value an int can have, -231.
		static constexpr int MIN_VALUE = std::numeric_limits<int>::min();
		// The number of bits used to represent an int value in two's complement binary form.
		static int SIZE;

		// static Class<Integer> 	TYPE
		// The Class instance representing the primitive type int.

		// Life Time Management
		Integer(int a)
			: val(a)
		{ }

	public:
		// methods
		// Returns the number of one-bits in the two's complement binary representation of the specified int value.
		static int bitCount(int i)
		{
			return Helper::popcount(i);
		}
		// Returns the value of this Integer as a byte after a narrowing primitive conversion.
		byte byteValue()
		{
			return static_cast<byte>(val);
		}

		// TODO: Implement compare method.
		// Compares two int values numerically.
		// static int compare(int x, int y) { }

		// Compares two Integer objects numerically.
		// int compareTo(Integer anotherInteger) { }

		// Compares two int values numerically treating the values as unsigned.
		// static int compareUnsigned(int x, int y) { }

		// Decodes a String into an Integer.
		static Integer decode(String nm)
		{
			return {Helper::BinaryStringToDecimal(nm)};
		}
		// Returns the unsigned quotient of dividing the first argument by the second where each argument and the result is interpreted as an unsigned value.
		static int divideUnsigned(int dividend, int divisor) { }
		// Returns the value of this Integer as a double after a widening primitive conversion.
		double doubleValue()
		{
			return static_cast<double>(val);
		}

		// TODO: Add Java gloabal lan.Object and implement this method.
		// Compares this object to the specified object.
		// boolean 	equals(Object obj) {}

		// Returns the value of this Integer as a float after a widening primitive conversion.
		float floatValue()
		{
			return static_cast<float>(val);
		}
		// Determines the integer value of the system property with the specified name.
		static Integer getInteger(String nm)
		{
			std::stringstream ss(nm);
			int _val = 0;
			ss >> _val;
			return {_val};
		}

		// TODO: Implement this methods
		// Determines the integer value of the system property with the specified name.
		static Integer getInteger(String nm, int val) { }
		// Returns the integer value of the system property with the specified name.
		static Integer getInteger(String nm, Integer val) { }
		// Returns a hash code for this Integer.

		int hashCode() { }
		// Returns a hash code for a int value; compatible with Integer.hashCode().
		static int hashCode(int value) { }
		// Returns an int value with at most a single one-bit, in the position of the highest-order ("leftmost") one-bit in the specified int value.
		static int highestOneBit(int i) { }
		// Returns the value of this Integer as an int.
		int intValue() const
		{
			return val;
		}
		// Returns the value of this Integer as a long after a widening primitive conversion.
		long longValue()
		{
			return static_cast<long>(val);
		}
		// Returns an int value with at most a single one-bit, in the position of the lowest-order ("rightmost") one-bit in the specified int value.
		static int lowestOneBit(int i) { }
		// Returns the greater of two int values as if by calling Math.max.
		static int max(int a, int b)
		{
			return (a < b) ? b : a;
		}
		// Returns the smaller of two int values as if by calling Math.min.
		static int min(int a, int b)
		{
			return (a < b) ? a : b;
		}
		// Returns the number of zero bits preceding the highest-order ("leftmost") one-bit in the two's complement binary representation of the specified int value.
		static int numberOfLeadingZeros(int i) { }
		// Returns the number of zero bits following the lowest-order ("rightmost") one-bit in the two's complement binary representation of the specified int value.
		static int numberOfTrailingZeros(int i) { }
		// Parses the string argument as a signed decimal integer.
		static int parseInt(String s)
		{
			std::stringstream ss(s);
			int _val = 0;
			ss >> _val;
			return _val;
		}
		// Parses the string argument as a signed integer in the radix specified by the second argument.
		static int parseInt(String s, int radix) { }
		// Parses the string argument as an unsigned decimal integer.
		static int parseUnsignedInt(String s) { }
		// Parses the string argument as an unsigned integer in the radix specified by the second argument.
		static int parseUnsignedInt(String s, int radix) { }
		// Returns the unsigned remainder from dividing the first argument by the second where each argument and the result is interpreted as an unsigned value.
		static int remainderUnsigned(int dividend, int divisor) { }
		// Returns the value obtained by reversing the order of the bits in the two's complement binary representation of the specified int value.
		static int reverse(int i) { }
		// Returns the value obtained by reversing the order of the bytes in the two's complement representation of the specified int value.
		static int reverseBytes(int i) { }
		// Returns the value obtained by rotating the two's complement binary representation of the specified int value left by the specified number of bits.
		static int rotateLeft(int i, int distance) { }
		// Returns the value obtained by rotating the two's complement binary representation of the specified int value right by the specified number of bits.
		static int rotateRight(int i, int distance) { }
		// Returns the value of this Integer as a short after a narrowing primitive conversion.
		short shortValue() { }
		// Returns the signum function of the specified int value.
		static int signum(int i) { }
		// Adds two integers together as per the + operator.
		static int sum(int a, int b) { }
		// Returns a string representation of the integer argument as an unsigned integer in base 2.
		static String toBinaryString(int i) { }
		// Returns a string representation of the integer argument as an unsigned integer in base 16.
		static String toHexString(int i) { }
		// Returns a string representation of the integer argument as an unsigned integer in base 8.
		static String toOctalString(int i) { }
		// Returns a String object representing this Integer's value.
		String toString()
		{
			return std::to_string(val);
		}
		// Returns a String object representing the specified integer.
		static String toString(int i)
		{
			return std::to_string(i);
		}
		// Returns a string representation of the first argument in the radix specified by the second argument.
		static String toString(int i, int radix) { }
		// Converts the argument to a long by an unsigned conversion.
		static long toUnsignedLong(int x) { }
		// Returns a string representation of the argument as an unsigned decimal value.
		static String toUnsignedString(int i) { }
		// Returns a string representation of the first argument as an unsigned integer value in the radix specified by the second argument.
		static String toUnsignedString(int i, int radix) { }
		// Returns an Integer instance representing the specified int value.
		static Integer valueOf(int i) { }
		// Returns an Integer object holding the value of the specified String.
		static Integer valueOf(String s) { }
		// Returns an Integer object holding the value extracted from the specified String when parsed with the radix given by the second argument.
		static Integer valueOf(String s, int radix) { }

	private:
		int val;
	};
} // namespace Javalike::Lang

#endif /* End of include guard : JAVA_LANG_INTEGER_HPP */