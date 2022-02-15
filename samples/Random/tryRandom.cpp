#include "helpers/JavalikeType.hpp"
#include <iostream>
#include <lang/util/Random.hpp>
#include <memory>
#include <thread>
#include <chrono>

using namespace Javalike::Util;

namespace Sample::Rnd {
    void randomSamples() {
        var rd = std::make_unique<Random>();
        int iterVal = 5;

        std::cout << "Test for Random Boolean" << '\n';
        for (int i = 0; i < iterVal; ++i) {
            std::cout << rd->nextBoolean() << "  --  ";
        }
        std::cout << '\n';

        std::cout << "Test for Random Int" << '\n';
        for (int i = 0; i < iterVal; ++i) {
            std::cout << rd->nextInt() << "  --  ";
        }
        std::cout << '\n';


        std::cout << "Test for Random In 0 - bound 10" << '\n';
        for (int i = 0; i < iterVal; ++i) {
            std::cout << rd->nextInt(10) << "  --  ";
        }
        std::cout << '\n';


        std::cout << "Test for Random Float" << '\n';
        for (int i = 0; i < iterVal; ++i) {
            std::cout << rd->nextFloat() << "  --  ";
        }
        std::cout << '\n';


        std::cout << "Test for Random Double" << '\n';
        for (int i = 0; i < iterVal; ++i) {
            std::cout.precision(17);
            std::cout << rd->nextDouble() << "  --  ";
        }
        std::cout << '\n';


        std::cout << "Test for Random Gaussian" << '\n';
        for (int i = 0; i < iterVal; ++i) {
            std::cout.precision(17);
            std::cout << rd->nextGaussian() << "  --  ";
        }
        std::cout << '\n';

        std::cout << "Test for Random Long" << '\n';
        for (int i = 0; i < iterVal; ++i) {
            std::cout << rd->nextLong() << "  --  ";
        }
        std::cout << '\n';


        std::cout << "Test for Random ByteArray" << '\n';
        JavalikeType::Array<std::byte> bytes(5);
        // JavalikeType::Array<std::byte> bytes {
        //     std::byte(0), 
        //     std::byte(0), 
        //     std::byte(0), 
        //     std::byte(0), 
        //     std::byte(0)
        // };
        rd->nextBytes(bytes);
        for (int i = 0; i < iterVal; ++i) {
            std::cout << (int)bytes[i] << "  --  ";
        }
        std::cout << '\n';
    }
}