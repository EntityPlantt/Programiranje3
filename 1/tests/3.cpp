#include "../impl.hpp"
#include <iostream>
using namespace std;

int main() {
	int arr[] = {1142, 356, 865, 626, 90, 1391};
	cout << "Original array: ";
	printarr(arr, 6);
	bubblesort(arr, 6);
	cout << "Sorted array: ";
	printarr(arr, 6);
	cout << "Bonus: cast as char: ";
	for (int i = 0; i < 6; i++) cout << char(arr[i]);
	cout << endl;
}