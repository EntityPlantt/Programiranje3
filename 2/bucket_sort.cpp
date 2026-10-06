#include "bucket_sort.hpp"
#include <algorithm>

void bucket_sort(int *arr, int n, int k) {
	auto [lp, rp] = std::minmax_element(arr, arr + n);
	int l = *lp, r = *rp;
	// Сите елементи во низата се меѓу l и r.
	// Интервалот [l, r] ќе го поделиме на скоро еднакви
	// k дисјунктни интервали, па сите елементи од одреден
	// интервал ќе спаѓаат во соодветната „кофа“.
	// Кофата i ќе ги содржи елементите од интервалот [l+i*(r-l+1)/k,l+(i+1)*(r-l+1)/k-1]
	// Елементот i ќе спаѓа во кофата (i-l)*k/(r-l+1)
	int bucketOf[n], bucketOffset[k], sorted[n];
	#pragma GCC ivdep
	for (int i = 0; i < k; i++) bucketOffset[i] = 0;
	for (int i = 0; i < n; i++) {
		++bucketOffset[bucketOf[i] = int64_t(arr[i] - l) * k / (r - l + 1)];
	}
	for (int i = 1; i < k; i++) bucketOffset[i] += bucketOffset[i - 1];
	for (int i = 0; i < n; i++) {
		sorted[--bucketOffset[bucketOf[i]]] = arr[i];
	}
	std::copy(sorted, sorted + n, arr);
	for (int i = 1; i < k; i++) {
		std::sort(arr + bucketOffset[i - 1], arr + bucketOffset[i]);
	}
	std::sort(arr + bucketOffset[k - 1], arr + n);
}