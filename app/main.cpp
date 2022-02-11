#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <vector>

#include <Math.hpp>
#include <helpers/JavalikeType.hpp>

namespace App
{
	_interface Deneme{};
	static void Main(std::vector<std::string> args)
	{
		(void)fprintf(stdout, "%s", "Welcome to JavaLike Project");

		std::thread th([]() {
			while(true)
			{
				(void)fprintf(stdout, "%lf\n", Javalike::Lang::Math::random());
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
			}
		});

		th.join();
	}
} // namespace App

int main(int argc, char* argv[])
{
	App::Main({argv + 1, argc + argv});
	return 0;
}