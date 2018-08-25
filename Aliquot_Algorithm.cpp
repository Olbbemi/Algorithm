/**-------------------------------------------------------------------------------------------------
  * 방법 1: 1 ~ N 까지 모든 수를 N에 대한 나머지연산을 할 때 그 값이 0인 데이터 [ O(N) ]
  * 방법 2: 모든 약수는 한 쌍으로 구성되며 중복 [ 6의 약수: (1, 6), (2, 3), (3, 2), (6, 1) ]
  *         -> 1 ~ Sqrt(N) 까지 모든 수를 N에 대한 나머지연산을 할 때 그 값이 0인 데이터 [ O(sqrt(N)) ]
  *-------------------------------------------------------------------------------------------------*/

// 방법 1.
queue<int> Store;
void Aliquot_Algorithm(int N)
{
	for (int i = 1; i <= N; i++)
	{
		if (N % i == 0)
			Store.push(i);
	}
}

// 방법 2.
stack<int> Top;
queue<int> Store;
void Aliquot_Algorithm(int N)
{
	int i = 1;
	for (; i * i < N; i++)
	{
		if (N % i == 0)
			Top.push(i);
	}
		
	if (i * i == N)
		Top.push(i);

	while (Top.empty() != 1)
	{
		Store.push(Top.top());
		Store.push(N / Top.top());
		Top.pop();
	}
}