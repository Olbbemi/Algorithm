# Aliquot Algorithm

**Aliquot** : 특정 수 N 에 대해서 N % i == 0 인 i 값들을 N 의 약수

- 일반적 해법 : 1 부터 N 까지 모든 수를  N 에 대해 나머지 연산을 할 때 그 값이 0 인 수를 기록

- 개선된 해법 : 모든 약수는 한 쌍으로 구성되며 이 쌍은 중복이 됨 

  ​	N까지 비교할 필요 없이 sqrt(N) 까지만 비교해도 충분히 약수를 구할 수 있음 

~~~c++
void General_Aliquot(int N)
{
	for(int i = 1; i <= N; i++)
	{
		if(N % i == 0)
			/* 약수 o */
		else
		    /* 약수 x */
	}
}

void Advanced_Aliquot(int N)
{
	int i = 1;
	for(; i * i < N; i++)
	{
		if(N % i == 0)
			/* 약수 o -> Push(i) */
		else
		    /* 약수 x */
	}
	
	if(i * i == N)
		/* 약수 o -> Push(i) */
	
	while(Top != NULL)
	{
		temp = Pop();
		/* N / temp 또한 N 의 약수  */
	}
}
~~~
