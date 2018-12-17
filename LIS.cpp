/**--------------------------------------------------------------------------------------------------
  *	LIS(Longest Increasing Subsequence) : 수가 증가하는 형태를 띤 부분 집합의 최대 길이를 구하는 알고리즘
  *	1 100 2 50 60 3 5 6 7 8 일 때
		-> 1 2 3 5 6 7 8 이 최장 증가 부분 수열		
  *--------------------------------------------------------------------------------------------------*/

// (N * N)
int D[N], C[N], R[N];

void LIS()
{
	// D[] : 데이터가 저장된 배열
	// C[] : 해당 위치에서 증가 부분 수열의 개수(초기값 : 1)
	// R[] : LIS의 경로를 찾기위해 인덱스를 저장하는 배열(초기값 : -1)

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
		/*	v[s.top()] 출력 */
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
	
	// 최종 ans.size() : LIS 값
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
		/* v[s.top()] 출력 */
		s.pop();
	}
}