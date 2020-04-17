

//====================================================================
// to display time calculated by the code
// elaspsed time

#include <chrono>

auto start = std::chrono::steady_clock::now();
/* put code in here */
auto end = std::chrono::steady_clock::now();
double time = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
std::cout << "time = " << time / 1e9 << std::endl;