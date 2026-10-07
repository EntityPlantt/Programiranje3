#include "bucket_sort.hpp"
#include <iostream>
#include <algorithm>

int main() {
	int a[] = {5, 4, 1, 2, 6, 7, 9, 3, 8, 0};
	bucket_sort(a, 10, 3);
	if (std::is_sorted(a, a + 10)) std::cout << "Successfully sorted 10 element array!\n";
	else {
		std::cout << "Array not sorted successfully!\nOutput:";
		for (int &i : a) std::cout << ' ' << i;
		std::cout << '\n';
		return 1;
	}
}