#pragma once
#include "_sort.h"
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;

void test_straight_sort()
{//ֱ�Ӳ�������
	int arr[] = { 1, 5, 7, 9, 2, 3 };
	cout << "����ǰ���У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
	zr::straight_sort(arr, 6);
	cout << "��������У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void test_shell_sort()
{//ϣ������
	int arr[] = { 1, 5, 7, 9, 2, 3 };
	cout << "����ǰ���У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
	zr::shell_sort(arr, 6);
	cout << "��������У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void test_select_sort()
{//ѡ������
	int arr[] = { 1, 5, 7, 9, 2, 3 };
	cout << "����ǰ���У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
	zr::select_sort(arr, 6);
	cout << "��������У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void test_quick_sort()
{//��������
	std::vector<int> arr;
	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(9);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);
	cout << "����ǰ���У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
	zr::quick_sort(0, 5, arr);
	cout << "��������У�";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void test_merge_sort()
{
	int arr[] = { 1,3,5,7,9,6,4,2 };
	cout << "����ǰ���У�";
	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
	cout << endl;
	zr::merge_sort(arr, 0, 7);
	cout << "��������У�";
	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
	cout << endl;	
}
void test_bucket_sort()
{
	int arr[] = { 1,3,5,7,9,6,4,2 };
	cout << "����ǰ���У�";
	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
	cout << endl;
	zr::bksort(arr, 8);
	cout << "��������У�";
	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void test_heap_sort()
{
	int arr[] = { 1,3,5,7,9,6,4,2 };
	cout << "����ǰ���У�";
	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
	cout << endl;
	zr::heap_sort(arr, 8);
	cout << "��������У�";
	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{	
	test_heap_sort();
	return 0;
}