#include "impl.hpp"
#include <iostream>
using namespace std;

void printarr(const int *arr, const int n) {
	for (int i = 0; i < n; i++) {
		cout << *arr << ' ';
		++arr;
	}
	cout << endl;
}

void printarralt(const int *arr, const int *const end) {
	while (arr != end) {
		cout << *arr << ' ';
		++arr;
	}
	cout << endl;
}

void printarrrec(const int *const arr, const int n) {
	if (n) {
		cout << *arr << ' ';
		printarrrec(arr + 1, n - 1);
	}
	else cout << endl;
}

void swap_deref(int *const a, int *const b) {
	const int t = *a;
	*a = *b;
	*b = t;
}

void swap_ref(int &a, int &b) {
	const int t = a;
	a = b;
	b = t;
}

void swap_xor(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

// sekoja iteracija gi gura pogolemite elementi poveke
// pati nadesno, dodeka pomalite samo ednas nalevo max
// sekoja iteracija min eden najgolem element go stava
// na kraj na nizata
void bubblesort(int *const arr, const int n) {
	for (int i = n; i; i--) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[j - 1]) {
				swap_xor(arr[j], arr[j - 1]);
			}
		}
	}
}

// binary search vo [l, r] kade intervalot
// sekogas se namaluva striktno
int bsearch(const int *const arr, const int n, const int val) {
	int l = 0, r = n - 1;
	while (l <= r) {
		const int m = (l + r) >> 1;
		if (arr[m] == val) return m;
		if (arr[m] < val) l = m + 1;
		else r = m - 1;
	}
	return -1;
}

// actual recursive function
static int bsearch_rec(const int *const arr, const int val, const int l, const int r) {
	if (l > r) return -1;
	const int m = (l + r) >> 1;
	if (arr[m] == val) return m;
	if (m[arr] < val) return bsearch_rec(arr, val, m + 1, r);
	return bsearch_rec(arr, val, l, m - 1);
}

// wrapper
int bsearch_rec(const int *const arr, const int n, const int val) {
	return bsearch_rec(arr, val, 0, n - 1);
}