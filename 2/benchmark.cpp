#include "bucket_sort.hpp"
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

int main(int argc, char **argv) {
	if (argc != 6) {
		cout << "Usage: " << *argv << " [seed] [low] [hi] [buckets] [size]\nAll inputs are integers\n";
		return 1;
	}
	int seed = atoi(argv[1]),
		l = atoi(argv[2]),
		r = atoi(argv[3]),
		k = atoi(argv[4]),
		n = atoi(argv[5]);
	std::cout << "Sorting " << n << " elements with " << k << " buckets\nseed = " << seed << ", elements are in [" << l << ", " << r << "]\n";
	int a[n];
	srand(seed);
	for (int &i : a) i = rand() % (r - l + 1) - l;
	std::cout << "START!" << std::endl;
	auto startTime = steady_clock::now().time_since_epoch();
	bucket_sort(a, n, k);
	auto time = steady_clock::now().time_since_epoch() - startTime;
	cout << "\nTIME!!!\nElapsed: "
	<< duration_cast<hours>(time) << ' '
	<< duration_cast<minutes>(time % 1h) << ' '
	<< duration_cast<seconds>(time % 1min) << ' '
	<< duration_cast<microseconds>(time % 1s) << "\nCheck sort... ";
	if (is_sorted(a, a + n)) return cout << "Array is sorted!", 0;
	return cout << "Array is NOT sorted!\n", 1;
}