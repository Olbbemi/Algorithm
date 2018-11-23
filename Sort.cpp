/*
// 오름차순 기준

	Bubble Sort : 인접한 데이터와 크기를 비교하여 정렬하는 방식, 정렬코드가 한번 동작하면 가장 큰 값은 정렬됨
				-> BigO : pow(N,2) 

		-> 데이터가 큰 값은 한 번 정렬될 때마다 가장 뒤로 정렬이 되지만 그 이외 값은 한 칸씩만 이동 

				1 5 3 2 10
					-> 1 3 2 5 10
						-> 1 2 3 5 10

	Shaker Sort : 버블정렬은 오직 한방향으로만 이동하면서 가장 큰 값을 정렬하는 방식 , 쉐이커정렬은 양방향으로 이동하면서 한번은 가장 큰 값을 정렬 남은 한번은 가장 작은 값을 정렬하는 방식 [ 데이터가 N 개라면 전체적으로 N / 2 만 보면 됨 ]
				-> BigO : pow(N,2)	  

	Select Sort : 버블 정렬과 반대로 가장 작은 값을 탐색하여 앞에서 부터 순차적으로 정렬하는 방식, 정렬코드가 한번 동작하면 가장 작은 값이 정렬됨
	 			-> BigO : pow(N,2)
	
	Insert Sort : 선택정렬과 비슷하지만 앞에서부터 순차적으로 정렬하는 방식이아닌 각 데이터가 정렬될 위치를 탐색하여 중간에 삽입되어 정렬 
				-> BigO : pow(N,2) || pow(N,1.5)
				
	Comb Sort , Shell Sort : 삽입정렬 또한 결국 모든 데이터를 하나씩 다 비교해야하므로 비효율적, 간격을 두어 간격끼리만 정렬하는 방법 [ Interval : N / 2 (Shell) , N / 1.3 (Comb) ] 
				-> BigO : pow(N,2)
	
	Quick Sort , Merge Sort : Divide & Conquer 방식을 이용하여 데이터를 빠르게 정렬, 재귀적 호출을 많이 사용하므로 위 정렬들 보다는 메모리측면에서는 비효율적 
				-> BigO : nlogn
				
	Heap Sort : 자료구조 힙을 이용하여 데이터를 정렬 
				-> BigO : nlogn
	
	Counting Sort : 정렬하고자하는 데이터의 개수를 이용하여 정렬하는 방식, 매우 빠른 처리속도를 가지고 있으나 개수를 세기위해서는 배열이 정렬해야할 데이터의 최대값만큼 가지고 있어야하므로 메모리측면에서 비효율적 
				-> BigO : n
	
	Radix Sort : 동일한 길이를 가지는 데이터를 버킷을 이용하여 뒤에서부터 차레대로 정렬하는 방식, 동일한 데이터를 가지지 않아도 정렬이 가능하나 최선의 속도는 보장 못함 
				-> BigO : n
*/

// Bubble Sort
for (i = 0; i < N; i++)
{
	for (j = i + 1; j < N; j++)
	{
		if (arr[i] > arr[j])
			Swap(arr[i], arr[j]);
	}
}

// Shaker Sort
for(i = 0; i < N / 2; i++)
{
	for(j = i + 1; j < N - i; j++)
	{
		if (arr[j - 1] > arr[j])
			Swap(arr[j - 1], arr[j]);
	}
	
	for(j = N - i - 1; j > i; j--)
	{
		if(arr[j - 1] > arr[j])
			Swap(arr[j - 1], arr[j]);
	}
}

// Select Sort
for (i = 0; i < N; i++)
{
	index = -1;
	min = INF;

	for (j = i; j < N; j++)
	{
		if (arr[j] < min)
		{
			index = j;
			min = arr[j];
		}
	}
				
	Swap(arr[i], arr[index]);
}

// Insert Sort
for (i = 0; i < N; i++)
{
	for (j = i - 1; 0 <= j && arr[i] < arr[j]; j--)
		arr[j + 1] = arr[j];
		
	arr[j + 1] = arr[i];
}

// Shell Sort
void Interval()
{
	interval = N / 2; /* comb: [N / 1.3] */
	while (1 <= interval)
	{
		for(i = 0; i < N; i++)
			Shell(arr, i, N, interval);
		interval /= 2;
	}
}

void Shell(int arr[], int start, int end, int interval)
{
	for (int i = start + interval; i < end; i += interval)
	{
		for (int j = i - interval; start <= j && arr[i] < arr[j]; j -= interval)
			arr[j + interval] = arr[j];
		
		arr[j + interval] = arr[i];
	}
}
	
// Merge Sort
void Divide(int arr[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;

		Divide(arr, start, mid);
		Divide(arr, mid + 1, end);
		Sort(arr, start, mid, end);
	}
}

void Sort(int arr[], int start, int mid, int end)
{
	int i, z = start, L = start, R = mid + 1;

	while (L <= mid && R <= end)
	{
		if (arr[L] < arr[R])
			temp[z++] = arr[R++];
		else
			temp[z++] = arr[L++];
	}

	if (L > mid)
	{
		for (i = R; i <= end; i++)
			temp[z++] = arr[i];
	}
	else
	{
		for (i = L; i <= mid; i++)
			temp[z++] = arr[i];
	}

	for (i = start; i <= end; i++)
		arr[i] = temp[i];
}
	
//Quick Sort
void Quick(int arr[], int start, int end)
{
	int L = start, R = end, pivot = arr[start], standard;
	
	while(start < end)
	{
		while(pivot <= arr[end] && start < end)
			end--;
			
		if(start != end)
			arr[start++] = arr[end];
			
		while(pivot >= arr[start] && start < end)
			start++;
			
		if(start != end)
			arr[end--] = arr[start];	
	}	
	
	arr[start] = pivot;
	standard = start;
	start = L;	end = R;
	
	if(start < standard)
		Quick(arr, start, standard - 1);
		
	if(standard < end)
		Quick(arr, standard + 1, end);
}

// Counting Sort
for(i = 0; i < N; i++)
	count[A[i]]++;

for(i = 1; i < N; i++)
	count[i] += count[i - 1];
	
for(i = 1; i < N; i++)
{
	result[count[A[i]]] = A[i];
	count[A[i]]--;
}