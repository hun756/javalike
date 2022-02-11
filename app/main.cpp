#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include <helpers/JavalikeType.hpp>

namespace App {
    _interface Deneme {};
    static void Main(std::vector<std::string> args)
    {
        (void)fprintf(stdout, "%s", "Welcome to JavaLike Project");
    }
}

int main(int argc, char* argv[]) { 
    App::Main({argv + 1, argc + argv});
    return 0;
}