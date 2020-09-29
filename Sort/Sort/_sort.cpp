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
		unsigned gap = len / INCRGAP + 1; // ������ʼ��,ע�������len<INCRGAPʱ��gapΪ0������Ϊ�˱�֤����ѭ����gap����Ϊ1������
		while (gap) // while gap>=1
		{
			for (unsigned i = gap; i < len; ++i) // ���飬��ÿ���������н��в�������
			{
				insertNum = a[i];//����ǰ��Ԫ��ֵ�ȴ���������������
				unsigned j = i;
				while (j >= gap && insertNum < a[j - gap])//Ѱ�Ҳ���λ��
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
		base = arr[left];  //ȡ����ߵ���Ϊ��׼��
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
		//��׼����λ
		arr[left] = arr[i];
		arr[i] = base;
		quick_sort(left, i - 1, arr);//�ݹ����
		quick_sort(i + 1, right, arr);//�ݹ��ұ�
	}


	void merge(int arr[], int l, int q, int r) {
		int n = r - l + 1;//��ʱ�����ϲ������������
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
		delete[] tmp;//ɾ���������ڴ�
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
			return;  //�ݹ�����������е�ÿ����������Ϊ����Ϊ1������
		int q = (l + r) / 2;
		merge_sort(arr, l, q);
		merge_sort(arr, q + 1, r);
		merge(arr, l, q, r);
	}

	void heap_build(int a[], int root, int length)
	{
		int lchild = root * 2 + 1;//���ڵ�����ӽ���±�
		if (lchild < length)//���ӽ���±겻�ܳ�������ĳ���
		{
			int flag = lchild;//flag�������ҽڵ������ֵ���±�
			int rchild = lchild + 1;//���ڵ�����ӽ���±�
			if (rchild < length)//���ӽ���±겻�ܳ�������ĳ���(����еĻ�)
			{
				if (a[rchild] > a[flag])//�ҳ������ӽ���е����ֵ
				{
					flag = rchild;
				}
			}
			if (a[root] < a[flag])
			{
				//���������ͱȸ����������ӽڵ�
				std::swap(a[root], a[flag]);
				//�Ӵ˴�����ӽڵ���Ǹ�λ�ÿ�ʼ�ݹ齨��
				heap_build(a, flag, length);
			}
		}
	}

	void heap_sort(int a[], int len)
	{
		for (int i = len / 2; i >= 0; --i)//�����һ����Ҷ�ӽڵ�ĸ���㿪ʼ����
		{
			heap_build(a, i, len);
		}

		for (int j = len - 1; j > 0; --j)//j��ʾ�����ʱ�ĳ��ȣ���Ϊlen�����Ѿ������ˣ���len-1��ʼ
		{
			std::swap(a[0], a[j]);//������βԪ��,�����ֵ��������������λ�ñ���
			heap_build(a, 0, j);//ȥ�����λ�õ�Ԫ�����½��ѣ��˴�j��ʾ����ĳ��ȣ����һ��λ���±��Ϊlen-2
		}

	}
}
