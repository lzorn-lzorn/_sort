#pragma once
#ifndef __SORT__
#define __SORT__
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define INCRGAP 2;
namespace zr
{
	void select_sort(int * arr, int len);
	void straight_sort(int * arr, int len);
	void shell_sort(int * arr, int len);
	void quick_sort(int left, int right, std::vector<int>& arr);
	void merge_sort(int arr[], int l, int r);
	void merge(int arr[], int l, int q, int r);
	void bksort(int * arr, int n);
	void heap_build(int a[], int root, int length);
	void heap_sort(int a[], int len);
}

#endif // !__SORT__

