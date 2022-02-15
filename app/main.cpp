#include <chrono>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <vector>


#include <Math.hpp>
#include <helpers/JavalikeType.hpp>

namespace
{
	void mathRand()
	{
		std::thread th([]() {
			while(true)
			{
				auto begin = std::chrono::high_resolution_clock::now();
				auto val = (float)rand() / (float)(RAND_MAX);
				auto end = std::chrono::high_resolution_clock::now();

				std::cout
					<< "Time Elapsed : "
					<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()
					<< std::endl;

				(void)fprintf(stdout, "%lf\n", val);

				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}
		});

		th.join();
	}
} // namespace

namespace App
{
	interface Deneme { };
	static void Main(std::vector<std::string> args)
	{
		(void)fprintf(stdout, "%s", "Welcome to JavaLike Project");
	}
} // namespace App

int main(int argc, char* argv[])
{
	App::Main({argv + 1, argc + argv});
	return 0;
}