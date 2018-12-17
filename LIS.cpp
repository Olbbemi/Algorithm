/**--------------------------------------------------------------------------------------------------
  *	LIS(Longest Increasing Subsequence) : ���� �����ϴ� ���¸� �� �κ� ������ �ִ� ���̸� ���ϴ� �˰���
  *	1 100 2 50 60 3 5 6 7 8 �� ��
		-> 1 2 3 5 6 7 8 �� ���� ���� �κ� ����		
  *--------------------------------------------------------------------------------------------------*/

// (N * N)
int D[N], C[N], R[N];

void LIS()
{
	// D[] : �����Ͱ� ����� �迭
	// C[] : �ش� ��ġ���� ���� �κ� ������ ����(�ʱⰪ : 1)
	// R[] : LIS�� ��θ� ã������ �ε����� �����ϴ� �迭(�ʱⰪ : -1)

	int result = 0, index = -1;
	stack<int> s;

	for (i = 0; i < N; i++)
	{
		C[i] = 1;

		for (j = 0; j < i; j++)
		{
			if (D[i] < D[j] && C[i] > C[j] + 1)
			{
				C[i] = C[j] + 1;
				R[i] = j;
			}
		}

		if (result < C[i])
		{
			result = C[i];
			index = i;
		}
	}

	// Back Tracking
	while (index != -1)
	{
		s.push(index);
		index = R[index];
	}

	while (s.empty() != 1)
	{
		/*	v[s.top()] ��� */
		s.pop();
	}
}

// (N * logN)
int D[N];
vector<int> ans;
vector<int> R;

void LIS()
{
	stack<int> s;
	ans.push_back(D[0]);
	R[0] = 0;
	
	for(int i = 1; i < N; i++)
	{
		if(ans.back() < D[i])
		{
			R[i] = ans.size();
			ans.push_back(D[i]);
		}
		else
		{
			int index = lower_bound(ans.begin(), ans.end(), D[i]);
			ans[index] = D[i];
			R[i] = index;
		}
	}	
	
	// ���� ans.size() : LIS ��
	int pivot = ans.size() - 1;
	for(int i = N - 1; i >= 0; i--)
	{
		if(pivot == R[i])
		{
			s.push(i);
			pivot--;
		}
	}
	
	while(s.empty() != 1)
	{
		/* v[s.top()] ��� */
		s.pop();
	}
}