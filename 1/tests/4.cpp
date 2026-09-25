#include "../impl.hpp"
#include <iostream>
using namespace std;

int main() {
	int arr[] = {1142, 356, 865, 626, 90, 1391};
	bubblesort(arr, 6);
	cout << "Sorted array: ";
	printarr(arr, 6);
	cout << "Checking if bsearch works:\n";
	for (int i = 0; i < 6; i++) {
		if (bsearch(arr, 6, i[arr]) == i) cout << "AC ";
		else cout << "WA ";
	}
	cout << "\nChecking if bsearch_rec works:\n";
	for (int i = 0; i < 6; i++) {
		if (bsearch_rec(arr, 6, i[arr]) == i) cout << "AC ";
		else cout << "WA ";
	}
	cout << endl;
}