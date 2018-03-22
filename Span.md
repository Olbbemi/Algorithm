**Span Algorithm** : 현재 시점에서 이전 시점들 중 현재 값보다 작거나 같은 값의 최대 연속일을 구하는 알고리즘

* 현재보다 이전 값들 중 현재 값보다 큰 값을 찾아 해당 인덱스를 현재 인덱스에서 감산
   * s.empty() != 1 만족하는동안 스택에 존재하는 값이 현재 값보다 작거나 같으면 pop , 크다면 break

   * s.empty() == 1 이면 p = -1 , s.empty() != 1 이면 S[i] = i - s.top(); 

     ​

~~~c++
stack<int> s;

void Span(int A[] , int N)
{
	for(i = 0; i < N; i++)
	{
		while(s.emtpy() != 1)
		{
			if(A[i] >= A[s.top()])
				s.pop();
			else
				break;
		}
		
		if(s.empty() == 1)
			p = -1;
		else
			p = s.top();
			
		S[i] = i - p;
		s.push(i);
	}
 }
~~~







