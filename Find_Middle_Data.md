# Find Middle Data

- **Find Middle Data** : 배열에서 중간값을 효율적으로 찾는 알고리즘
  - 정렬 후 (start +  end) / 2 위치에 있는 값이 중간 값
  - 중간값이라면 좌측에 있는 데이터의 개수와 우측에 있는 데이터의 개수가 동일 (우선순위 큐 사용)



- 최초값을 m 이라는 변수에 저장하고 m 보다 작으면 내림차순으로 선언된 우선순위 큐 배열 [less]

  ​	, m 보다 크면 오름차순으로 선언된 우선순위 큐 배열 [greater] 에 저장

  ​

  - less.size() > greater.size()	->	크기가 같을 때까지 greater 데이터를 less 로 이동
  - less.size() < greater.size()	->	크기가 같을 때까지 less 데이터를 greater 로 이동



~~~c++
priority_queue < int, vector<int>, less<int> > Less;
priority_queue< int, vector<int>, greater<int> > More;

while (Less.size() != More.size())
{
	if (Less.size() > More.size())
	{
		More.push(M);
		M = Less.front();
		Less.pop();
	}
	else
	{
		Less.push(M);
		M = More.front();
		More.pop();
	}
}
~~~

