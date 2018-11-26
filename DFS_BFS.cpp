/**--------------------------------------------------------------------------------------------------------------------------------------------------
  * 그래프 순회 : 모든 정점을 한번씩만 방문
		-> 인접 행렬 및 인접 리스트로 모두 구현이 가능 [ 문제에서 주로 정점의 크기가 작은 것부터 또는 큰 것부터로 정의하므로 리스트로 코딩할 떈 반드시 정렬 ] 
		
			- 인접행렬 : pow(V , 2) 	=> V 는 정점의 수 
			- 인접리스트 : V + E 	=> V 는 정점의 수 , E 는 간선의 수 

  * DFS : 깊이 우선 탐색이며 스택 또는 재귀 이용 
  * BFS : 너비 우선 탐색이며 큐 이용 [ 비가중치 그래프에서 최단 경로 탐색으로도 사용할 수 있음 ] 
  * 이분 그래프 : 그래프를 두 영역으로 구분할 수 있는 그래프 [ 각 영역에 속한 정점간은 연결되어 있지 않으며 모든 간선은 두 영역 사이를 이어야 함 ] 	
  *--------------------------------------------------------------------------------------------------------------------------------------------------*/

// DFS 인접 행렬
void DFS(int v, int N)
{
	if (check[v] == true)
		return;

	// v 출력		
	check[v] = true;
	for (i = 1; i <= N; i++)
	{
		if (A[v][i] != 0 && check[i] == false)
			DFS(i, N);
	}
}

// DFS 인접 리스트 (재귀)
void DFS(int v)
{
	if (check[v] == true)
		return;

	// v 출력		
	check[v] = true;
	for (i = 0; i < A[v].size(); i++)
		if (check[A[v][i]] == false)
			DFS(A[v][i]);
}

// DFS 인접 리스트 (비재귀)
stack<int> s;
void DFS(int v)
{
	check[v] = true;
	s.push(v);
	// s.top() 출력 

	while (s.empty() != 1)
	{
		bool flag = true;
		for (int i = 0; i < A[s.top()].size(); i++)
		{
			if (check[A[s.top()][i]] == false)
			{
				Check[A[s.top()][i]] = true;
				s.push(A[s.top()][i]);

				// s.top() 출력
				flag = false;
				break;
			}
		}

		if (flag == true)
			s.pop();
	}
}

// BFS 인접 행렬
queue <int> q;
void BFS(int v, int N)
{
	// v 출력
	q.push(v);	check[v] = true;

	while (q.empty() != 1)
	{
		v = q.front();	
		q.pop();

		for (i = 1; i <= N; i++)
		{
			if (A[v][i] != 0 && check[i] == false)
			{
				q.push(i);
				check[i] = true;
			}
		}
	}

}

// BFS 인접 리스트
queue <int> q;
void BFS(int v)
{
	// v 출력 
	check[v] = true;
	q.push(v);	

	while (q.emtpy() != 1)
	{
		v = q.front();	
		q.pop();

		for (i = 0; i < A[v].size(); i++)
		{
			if (check[A[v][i] == false)
			{
				q.push(i);
				check[i] = true;
			}
		}
	}
}