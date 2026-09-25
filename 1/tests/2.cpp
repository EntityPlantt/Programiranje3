#include "../impl.hpp"
#include <iostream>
using namespace std;

int main() {
	int a = 50200, b = 65535;
	cout << "Original: a = " << a << ", b = " << b << '\n';
	swap_deref(&a, &b);
	cout << "Swapped by pointer func: a = " << a << ", b = " << b << "\nUnswapping as references now...\n";
	swap_ref(a, b);
	cout << "Unswapped: a = " << a << ", b = " << b << "\nSPECIAL: XOR SWAP\n";
	swap_xor(a, b);
	cout << "Swapped: a = " << a << ", b = " << b << '\n';
}