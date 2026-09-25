#pragma once

// 1.1
void printarr(const int *arr, const int n);
void printarralt(const int *arr, const int *const end);
void printarrrec(const int *const arr, const int n);

// 1.2
void swap_deref(int *const a, int *const b);
void swap_ref(int &a, int &b);
void swap_xor(int &a, int &b);

// 1.3
void bubblesort(int *const arr, const int n);

// 1.4
int bsearch(const int *const arr, const int n, const int val);
int bsearch_rec(const int *const arr, const int n, const int val);

// 1.5
struct date {
	// ISO8601
	short year, month, day;
};
struct footballer {
	// new tech: variable length, also assignment works! marvelous!
	const char *name, *surname, *clubname;
	date birthdate;
};