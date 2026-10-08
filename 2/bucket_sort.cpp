#include "bucket_sort.hpp"
#include <cstring>
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
	// NOTE: имплементацијава е со динамичко алоцирање на меморија бидејќи дава segmentation fault обично!
	int *bucketOf = (int*) malloc(sizeof(int) * long(n));
	int *bucketOffset = (int*) malloc(sizeof(int) * long(k));
	memset(bucketOffset, 0, sizeof(int) * long(k));
	for (int i = 0; i < n; i++) {
		bucketOf[i] = int64_t(arr[i] - l) * k / (r - l + 1);
		// if (bucketOf[i] < 0 || bucketOf[i] >= k) std::cerr << "WRONG " << arr[i] << std::endl;
		++bucketOffset[bucketOf[i]];
	}
	for (int i = 1; i < k; i++) bucketOffset[i] += bucketOffset[i - 1];
	int *sorted = (int*) malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		sorted[--bucketOffset[bucketOf[i]]] = arr[i];
	}
	free(bucketOf);
	std::copy(sorted, sorted + n, arr);
	free(sorted);
	for (int i = 1; i < k; i++) {
		std::sort(arr + bucketOffset[i - 1], arr + bucketOffset[i]);
	}
	std::sort(arr + bucketOffset[k - 1], arr + n);
	free(bucketOffset);
}