# Circular Queue

- Linear Queue 문제점 : pop을 하면 front가 이동하면서 이전 배열 공간을 사용 할 수 없음
- **Circular Queue** : 논리적으로 배열의 시작과 끝을 연결 [% 연산을 이용]
  1. front , rear 은 0 으로 초기화
  2. front == rear 이면 Emtpy 상태
  3. (rear + 1) % N == front 이면 Full 상태
  4.  배열 전체 크기가 N 이면 최대 저장할 수 있는 데이터 개수는 N - 1 [ Full 과 Empty 를 구별하기위함]

~~~c
void Euqueue(int A[] , int D , int N)
{
	if((rear + 1) % N == front)
			/* Full */
	
	rear = (rear + 1) % N;
	A[rear] = D;
}

int Dequeue(int A[] , int N)
{
	if(front == rear)
		/*	Empty */
	
	front = (front + 1) % N;
	return A[front];
}
~~~

