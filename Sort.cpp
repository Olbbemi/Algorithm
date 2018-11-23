/*
// �������� ����

	Bubble Sort : ������ �����Ϳ� ũ�⸦ ���Ͽ� �����ϴ� ���, �����ڵ尡 �ѹ� �����ϸ� ���� ū ���� ���ĵ�
				-> BigO : pow(N,2) 

		-> �����Ͱ� ū ���� �� �� ���ĵ� ������ ���� �ڷ� ������ ������ �� �̿� ���� �� ĭ���� �̵� 

				1 5 3 2 10
					-> 1 3 2 5 10
						-> 1 2 3 5 10

	Shaker Sort : ���������� ���� �ѹ������θ� �̵��ϸ鼭 ���� ū ���� �����ϴ� ��� , ����Ŀ������ ��������� �̵��ϸ鼭 �ѹ��� ���� ū ���� ���� ���� �ѹ��� ���� ���� ���� �����ϴ� ��� [ �����Ͱ� N ����� ��ü������ N / 2 �� ���� �� ]
				-> BigO : pow(N,2)	  

	Select Sort : ���� ���İ� �ݴ�� ���� ���� ���� Ž���Ͽ� �տ��� ���� ���������� �����ϴ� ���, �����ڵ尡 �ѹ� �����ϸ� ���� ���� ���� ���ĵ�
	 			-> BigO : pow(N,2)
	
	Insert Sort : �������İ� ��������� �տ������� ���������� �����ϴ� ����̾ƴ� �� �����Ͱ� ���ĵ� ��ġ�� Ž���Ͽ� �߰��� ���ԵǾ� ���� 
				-> BigO : pow(N,2) || pow(N,1.5)
				
	Comb Sort , Shell Sort : �������� ���� �ᱹ ��� �����͸� �ϳ��� �� ���ؾ��ϹǷ� ��ȿ����, ������ �ξ� ���ݳ����� �����ϴ� ��� [ Interval : N / 2 (Shell) , N / 1.3 (Comb) ] 
				-> BigO : pow(N,2)
	
	Quick Sort , Merge Sort : Divide & Conquer ����� �̿��Ͽ� �����͸� ������ ����, ����� ȣ���� ���� ����ϹǷ� �� ���ĵ� ���ٴ� �޸����鿡���� ��ȿ���� 
				-> BigO : nlogn
				
	Heap Sort : �ڷᱸ�� ���� �̿��Ͽ� �����͸� ���� 
				-> BigO : nlogn
	
	Counting Sort : �����ϰ����ϴ� �������� ������ �̿��Ͽ� �����ϴ� ���, �ſ� ���� ó���ӵ��� ������ ������ ������ �������ؼ��� �迭�� �����ؾ��� �������� �ִ밪��ŭ ������ �־���ϹǷ� �޸����鿡�� ��ȿ���� 
				-> BigO : n
	
	Radix Sort : ������ ���̸� ������ �����͸� ��Ŷ�� �̿��Ͽ� �ڿ������� ������� �����ϴ� ���, ������ �����͸� ������ �ʾƵ� ������ �����ϳ� �ּ��� �ӵ��� ���� ���� 
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