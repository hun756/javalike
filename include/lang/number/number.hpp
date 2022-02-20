/**
 *  @file 
 *      number.hpp
 *  @author 
 *      Mehmet Ekemen (ekemenms@gmail.com)
 *  @brief  
 *      The abstract class Number is the superclass of platform classes representing numeric values 
 *      that are convertible to the primitive types byte, double, float, int, long, and short. 
 *      The specific semantics of the conversion from the numeric value of a particular Number implementation
 *      to a given primitive type is defined by the Number implementation in question. For platform classes, 
 *      the conversion is often analogous to a narrowing primitive conversion or a widening primitive conversion
 *      as defining in The Java™ Language Specification for converting between primitive types. Therefore, conversions 
 *      may lose information about the overall magnitude of a numeric value, may lose precision, and may even return a 
 *      result of a different sign than the input. See the documentation of a given Number implementation for conversion details.
 *  @version 0.1
 *  @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * @link 
 *  https://docs.oracle.com/javase/8/docs/api/java/lang/Number.html
 * @endlink
**/

#ifndef JAVA_LANG_NUMBER_HPP
#define JAVA_LANG_NUMBER_HPP

#include <cstddef>

namespace Javalike::Lang
{
	// Abstract number class.
	class Number
	{
	public:
		// Returns the value of the specified number as a byte, which may involve rounding or truncation.
		/* care */ virtual std::byte byteValue() = 0;

		// Returns the value of the specified number as a double, which may involve rounding.
		virtual double doubleValue() = 0;

		// Returns the value of the specified number as a float, which may involve rounding.
		virtual float floatValue() = 0;

		// Returns the value of the specified number as an int, which may involve rounding or truncation.
		virtual int intValue() = 0;

		// Returns the value of the specified number as a long, which may involve rounding or truncation.
		virtual long longValue() = 0;

		// Returns the value of the specified number as a short, which may involve rounding or truncation.
		/* care */ virtual short shortValue() = 0;
	};
} // namespace Javalike::Lang

#endif /* End of include guard : JAVA_LANG_NUMBER_HPP */