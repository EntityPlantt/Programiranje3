#include "../impl.hpp"
#include <iostream>
using namespace std;

int main() {
	int x[5] = {72, 76, 88};
	cout << "Size param: ";
	printarr(x, 5);
	cout << "End ptr param: ";
	printarralt(x, x + 5);
	cout << "Recursion: ";
	printarralt(x, x + 5);
}