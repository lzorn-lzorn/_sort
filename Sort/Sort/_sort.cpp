#include "_sort.h"
namespace zr
{
	void select_sort(int * arr, int len)
	{
		int min, index, temp;
		for (int i = 0; i < len; i++)
		{
			min = arr[i];
			index = i;
			for(int j = i + 1; j < len; j++)
				if (arr[j] < min)
				{
					min = arr[j];
					index = j;
				}
			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
		
	}
	void straight_sort(int * arr, int len)
	{
		int temp, i, j;
		for (int i = 1; i < len; i++)
		{
			temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
	}

	void shell_sort(int * a, int len)
	{
		int insertNum = 0;
		unsigned gap = len / INCRGAP + 1; // 步长初始化,注意如果当len<INCRGAP时，gap为0，所以为了保证进入循环，gap至少为1！！！
		while (gap) // while gap>=1
		{
			for (unsigned i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
			{
				insertNum = a[i];//将当前的元素值先存起来方便后面插入
				unsigned j = i;
				while (j >= gap && insertNum < a[j - gap])//寻找插入位置
				{
					a[j] = a[j - gap];
					j -= gap;
				}
				a[j] = insertNum;
			}
			gap = gap / INCRGAP;
		}

	}

	void quick_sort(int left , int right, std::vector<int>& arr)
	{
		if (left >= right)
			return;
		int i, j, base, temp;
		i = left, j = right;
		base = arr[left];  //取最左边的数为基准数
		while (i < j)
		{
			while (arr[j] >= base && i < j)
				j--;
			while (arr[i] <= base && i < j)
				i++;
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		//基准数归位
		arr[left] = arr[i];
		arr[i] = base;
		quick_sort(left, i - 1, arr);//递归左边
		quick_sort(i + 1, right, arr);//递归右边
	}


	void merge(int arr[], int l, int q, int r) {
		int n = r - l + 1;//临时数组存合并后的有序序列
		int* tmp = new int[n];
		int i = 0;
		int left = l;
		int right = q + 1;
		while (left <= q && right <= r)
			tmp[i++] = arr[left] <= arr[right] ? arr[left++] : arr[right++];
		while (left <= q)
			tmp[i++] = arr[left++];
		while (right <= r)
			tmp[i++] = arr[right++];
		for (int j = 0; j < n; ++j)
			arr[l + j] = tmp[j];
		delete[] tmp;//删掉堆区的内存
	}

	void bksort(int * arr, int n) {
		int i, j;
		int count = 0;
		int buckets[100];
		for (int i = 0; i < 100; i++)
			buckets[i] = 0;
		for (int i = 0; i < n; i++)
			buckets[arr[i]]++;
		for(int i = 0, j = 0; i < 100; i++)
			while (buckets[i] > 0)
			{
				arr[j] = i;
				buckets[i]--;
				j++;
				count++;
			}
		std::cout << count <<std:: endl;
	}


	void merge_sort(int arr[], int l, int r) {
		if (l == r)
			return;  //递归基是让数组中的每个数单独成为长度为1的区间
		int q = (l + r) / 2;
		merge_sort(arr, l, q);
		merge_sort(arr, q + 1, r);
		merge(arr, l, q, r);
	}

	void heap_build(int a[], int root, int length)
	{
		int lchild = root * 2 + 1;//根节点的左子结点下标
		if (lchild < length)//左子结点下标不能超出数组的长度
		{
			int flag = lchild;//flag保存左右节点中最大值的下标
			int rchild = lchild + 1;//根节点的右子结点下标
			if (rchild < length)//右子结点下标不能超出数组的长度(如果有的话)
			{
				if (a[rchild] > a[flag])//找出左右子结点中的最大值
				{
					flag = rchild;
				}
			}
			if (a[root] < a[flag])
			{
				//交换父结点和比父结点大的最大子节点
				std::swap(a[root], a[flag]);
				//从此次最大子节点的那个位置开始递归建堆
				heap_build(a, flag, length);
			}
		}
	}

	void heap_sort(int a[], int len)
	{
		for (int i = len / 2; i >= 0; --i)//从最后一个非叶子节点的父结点开始建堆
		{
			heap_build(a, i, len);
		}

		for (int j = len - 1; j > 0; --j)//j表示数组此时的长度，因为len长度已经建过了，从len-1开始
		{
			std::swap(a[0], a[j]);//交换首尾元素,将最大值交换到数组的最后位置保存
			heap_build(a, 0, j);//去除最后位置的元素重新建堆，此处j表示数组的长度，最后一个位置下标变为len-2
		}

	}
}
