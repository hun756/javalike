#ifndef JAVALIKE_TYPE_HELPER_HPP
#define JAVALIKE_TYPE_HELPER_HPP

#define interface struct
#define iFun virtual
#define var auto
#define boolean bool
#define extends :

#include <vector>



struct JavalikeType
{
    template<class T> using Array = std::vector<T>;;
};

#endif /* End of include guard : JAVALIKE_TYPE_HELPER_HPP */