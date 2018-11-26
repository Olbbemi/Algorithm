/**--------------------------------------------------------------------------------------------------------------------------------------------------
  * �׷��� ��ȸ : ��� ������ �ѹ����� �湮
		-> ���� ��� �� ���� ����Ʈ�� ��� ������ ���� [ �������� �ַ� ������ ũ�Ⱑ ���� �ͺ��� �Ǵ� ū �ͺ��ͷ� �����ϹǷ� ����Ʈ�� �ڵ��� �� �ݵ�� ���� ] 
		
			- ������� : pow(V , 2) 	=> V �� ������ �� 
			- ��������Ʈ : V + E 	=> V �� ������ �� , E �� ������ �� 

  * DFS : ���� �켱 Ž���̸� ���� �Ǵ� ��� �̿� 
  * BFS : �ʺ� �켱 Ž���̸� ť �̿� [ ����ġ �׷������� �ִ� ��� Ž�����ε� ����� �� ���� ] 
  * �̺� �׷��� : �׷����� �� �������� ������ �� �ִ� �׷��� [ �� ������ ���� �������� ����Ǿ� ���� ������ ��� ������ �� ���� ���̸� �̾�� �� ] 	
  *--------------------------------------------------------------------------------------------------------------------------------------------------*/

// DFS ���� ���
void DFS(int v, int N)
{
	if (check[v] == true)
		return;

	// v ���		
	check[v] = true;
	for (i = 1; i <= N; i++)
	{
		if (A[v][i] != 0 && check[i] == false)
			DFS(i, N);
	}
}

// DFS ���� ����Ʈ (���)
void DFS(int v)
{
	if (check[v] == true)
		return;

	// v ���		
	check[v] = true;
	for (i = 0; i < A[v].size(); i++)
		if (check[A[v][i]] == false)
			DFS(A[v][i]);
}

// DFS ���� ����Ʈ (�����)
stack<int> s;
void DFS(int v)
{
	check[v] = true;
	s.push(v);
	// s.top() ��� 

	while (s.empty() != 1)
	{
		bool flag = true;
		for (int i = 0; i < A[s.top()].size(); i++)
		{
			if (check[A[s.top()][i]] == false)
			{
				Check[A[s.top()][i]] = true;
				s.push(A[s.top()][i]);

				// s.top() ���
				flag = false;
				break;
			}
		}

		if (flag == true)
			s.pop();
	}
}

// BFS ���� ���
queue <int> q;
void BFS(int v, int N)
{
	// v ���
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

// BFS ���� ����Ʈ
queue <int> q;
void BFS(int v)
{
	// v ��� 
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