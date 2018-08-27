/**-----------------------------------
  * Min Heap: 모든 부모 노드는 자식 노드들 보다 작은 값을 가짐
  * Max Heap: 모든 부모 노드는 자식 노드들 보다 큰 값을 가짐
  * 힙은 항상 완전이진트리 구조를 만족해야 하며 배열을 이용
  * 시작인덱스를 0부터 시작하면서 현재 노드의 인덱스가 i일 때 해당 노드의 부모 노드 [ (i - 1) / 2 ], 해당 노드의 좌측 자식 노드 [ i * 2 + 1 ], 우측 자식 노드 [ i * 2 + 2 ] 
  *----------------------------------- */

#define Max_Array 100

struct ST_Heap
{
	int arr[Max_Array];
	int size;
};

/**-------------------------
  * 데이터가 들어올 때마다 현재 인덱스를 기준으로 부모와 비교하여 위치를 조정
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
  * 데이터가 들어올 때마다 조정하는 것이 아닌 배열에 전체 데이터를 저장
  * 전체 데이터 크기 / 2 부터 자식노드와 비교하여 위치를 조정 [ 전체 데이터 크기 / 2 위치: 단말 노드가 아닌 노드 중 인덱스가 가장 큰 노드를 의미 ]
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