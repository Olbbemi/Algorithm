/**-----------------------------
  * Linear Queue 문제점: pop을 하면 front가 이동하면서 이전 배열 공간을 사용 할 수 없음
  * Circular Queue : % 연산을 이용하여 논리적으로 배열의 시작과 끝을 연결
  * front , rear 은 0 으로 초기화
  * front == rear 이면 Emtpy 상태
  * (rear + 1) % N == front 이면 Full 상태
  * 배열 전체 크기가 N 이면 최대 저장할 수 있는 데이터 개수는 N - 1 [ Full 과 Empty 를 구별하기위함]
  *------------------------------*/

#define Max_Array 100

int front = 0, rear = 0, queue[Max_Array];
void Euqueue(int D)
{
	if ((rear + 1) % Max_Array == front)
	{
		// queue is full;
	}

	rear = (rear + 1) % Max_Array;
	queue[rear] = D;
}

int Dequeue()
{
	if (front == rear)
	{
		// queue is empty;
	}

	front = (front + 1) % Max_Array;
	return queue[front];
}