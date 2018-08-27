/**-----------------------------------
  * Min Heap: ��� �θ� ���� �ڽ� ���� ���� ���� ���� ����
  * Max Heap: ��� �θ� ���� �ڽ� ���� ���� ū ���� ����
  * ���� �׻� ��������Ʈ�� ������ �����ؾ� �ϸ� �迭�� �̿�
  * �����ε����� 0���� �����ϸ鼭 ���� ����� �ε����� i�� �� �ش� ����� �θ� ��� [ (i - 1) / 2 ], �ش� ����� ���� �ڽ� ��� [ i * 2 + 1 ], ���� �ڽ� ��� [ i * 2 + 2 ] 
  *----------------------------------- */

#define Max_Array 100

struct ST_Heap
{
	int arr[Max_Array];
	int size;
};

/**-------------------------
  * �����Ͱ� ���� ������ ���� �ε����� �������� �θ�� ���Ͽ� ��ġ�� ����
  *-------------------------*/
ST_Heap heap;
void Insertion(int data)
{
	int index = heap.size++;
	while (index != 0 && data < heap.arr[(index - 1) / 2])
	{
		heap.arr[index] = heap.arr[(index - 1) / 2];
		index = (index - 1) / 2;
	}

	heap.arr[index] = data;
}

/**-------------------------
  * �����Ͱ� ���� ������ �����ϴ� ���� �ƴ� �迭�� ��ü �����͸� ����
  * ��ü ������ ũ�� / 2 ���� �ڽĳ��� ���Ͽ� ��ġ�� ���� [ ��ü ������ ũ�� / 2 ��ġ: �ܸ� ��尡 �ƴ� ��� �� �ε����� ���� ū ��带 �ǹ� ]
  *-------------------------*/
void Adjust()
{
	for (int i = heap.size / 2; 0 <= i; i--)
	{
		int temp = i;
		while (1)
		{
			int index = -1,	comp = heap.arr[temp];

			if (temp * 2 + 1 >= heap.size)
				break;

			if (heap.arr[temp * 2 + 1] < comp)
			{
				comp = heap.arr[temp * 2 + 1];
				index = temp * 2 + 1;
			}

			if (temp * 2 + 2 < heap.size && heap.arr[temp * 2 + 2] < comp)
			{
				comp = heap.arr[temp * 2 + 2];
				index = temp * 2 + 2;	
			}

			if (index != -1)
			{
				int swap = heap.arr[temp];
				heap.arr[temp] = comp;
				heap.arr[index] = swap;
				temp = index;
			}
			else
				break;
		}
	}
}

int Delete()
{
	int return_value = -1;

	if (heap.size == 0)
	{
		// heap is empty;
	}
	else if (heap.size == 1)
	{
		return_value = heap.arr[0];
		heap.size = 0;
	}
	else
	{
		return_value = heap.arr[0];

		int parent = 0, child = 1;
		int comp = heap.arr[heap.size--];

		while (child <= heap.size)
		{
			if (child < heap.size && heap.arr[child + 1] < heap.arr[child])
				child++;

			if (comp <= heap.arr[child])
				break;
			else
			{
				heap.arr[parent] = heap.arr[child];
				parent = child;
				child = child * 2 + 1;
			}
		}

		heap.arr[parent] = comp;
	}

	return return_value;
}