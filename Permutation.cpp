/**---------------------------------------------------------------------------------------------------
  * 순열 (Permutation): 1 ~ N 사이의 수로 이루어진 수열 [1 ~ N 사이 수를 반드시 한번씩만 사용] 
  * 순열의 개수 : 크기가 N 인 순열의 총 개수는 N!
	
  * 현재 순열 정보가 정상적이라면 이전 순열 및 다음 순열를 얻을 수 있음

  * 이전순열
	  - A[i - 1] > A[i] 를 만족하는 가장 큰 i를 찾음
	  - j >= i 이면서 A[i - 1] > A[j] 을 만족하는 가장 큰 j를 찾음
	  - A[j] 와  A[i - 1] 을 swap
	  - A[i] 부터 배열의 끝을 reverse

  * 다음순열
	  - A[i - 1] < A[i] 를 만족하는 가장 큰 i를 찾음 
	  - j >= i 이면서 A[i - 1] < A[j] 을 만족하는 가장 큰 j를 찾음 
	  - A[j] 와  A[i - 1] 을 swap
	  - A[i] 부터 배열의 끝을 reverse
	
  * 모든 순열 : 크기가 N 인 순열을 다음 순열 또는 이전 순열을 이용하여 처음부터 끝까지 나열 => BigO(N * N!)  
  *---------------------------------------------------------------------------------------------------*/

// Prev-Permutation
bool prev(int N)
{
	int i, j, temp;
	for (i = N; i > 1; i--)
	{
		if (D[i - 1] > D[i])
			break;
	}

	if (i <= 1)
		return false;

	for (j = N; j >= i; j--)
	{
		if (D[i - 1] > D[j])
			break;
	}

	swap(D[j], D[i - 1]);
	reverse(&D[i], &D[N + 1]);
	return true;
}

// Next-Permutation
bool next(int N)
{
	int i, j, temp;
	for (i = N; i > 1; i--)
	{
		if (D[i - 1] < D[i])
			break;
	}

	if (i <= 1)
		return false;

	for (j = N; j >= i; j--)
	{
		if (D[i - 1] < D[j])
			break;
	}

	swap(D[j], D[i - 1]);
	reverse(&D[i], &D[N + 1]);
	return true;
}