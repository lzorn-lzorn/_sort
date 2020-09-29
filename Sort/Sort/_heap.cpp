#include "_heap.h"
namespace zr
{
	using namespace std;

	void Print()
	{
		for (int i = 0; i < n; i++)
			cout << heap[i] << " ";
		cout << endl;
	}
	void DownAdjust(int low, int high)
	{
		int i = low, j = i * 2;
		while (j <= high)
		{
			if (j + 1 <= high && heap[j + 1] > heap[j])
				j = j + 1;
			if (heap[j] > heap[i])
			{
				swap(heap[j], heap[i]);
				i = j;
				j = i * 2;
			}
			else
				break;
		}

	}
	void CreateHeap()
	{
		for (int i = n / 2; i >= 1; i--)
			DownAdjust(i, n);
	}
	void DeleteTop()
	{
		heap[1] = heap[n--];
		DownAdjust(1, n);
	}
	void UpAdjust(int low, int high)
	{
		int i = high, j = i / 2;
		while (j >= low)
		{
			if (heap[j] < heap[i])
			{
				swap(heap[j], heap[i]);
				i = j;
				j = i / 2;
			}
			else
				break;
		}
	}
	void Insert(int x)
	{
		heap[++n] = x;
		UpAdjust(1, n);
	}
	void HeapSort()
	{
		CreateHeap();
		for (int i = n; i > 1; i--)
		{
			swap(heap[i], heap[1]);
			DownAdjust(1, i - 1);
		}

	}

}
