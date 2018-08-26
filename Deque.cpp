/**-------------------------
  * 양방향 리스트를 사용하며 양 끝에서 데이터의 삽입 및 삭제가 모두 가능한 자료구조
  * 포인터 저장을 Xor 연산자를 통하여 단방향 리스트이지만 양방향으로 이동가능한 구조 사용 
  *-------------------------*/

#include <stdint.h>

struct DEQUE
{
	int data;
	struct DEQUE * link;
};

DEQUE *front = nullptr, *rear = nullptr;
void front_Euqueue(int D)
{
	DEQUE* data = (DEQUE*)malloc(sizeof(DEQUE));

	if (front == nullptr && rear == nullptr)
		front = rear = data;

	front->link = (DEQUE*)((uintptr_t)data ^ (uintptr_t)front->link);
	data->link = (DEQUE*)((uintptr_t)front ^ NULL);
	front = data;
}

void rear_Enqueue(int D)
{
	DEQUE* data = (DEQUE*)malloc(sizeof(DEQUE));

	if (front == nullptr && rear == nullptr)
		front = rear = data;

	rear->link = (DEQUE*)((uintptr_t)data ^ (uintptr_t)rear->link);
	data->link = (DEQUE*)((uintptr_t)rear ^ NULL);
	rear = data;
}

void front_Dequeue()
{
	if (front == nullptr)
	{
		// deque is empty;
	}

	DEQUE* garbage = front;
	front = (DEQUE*)((uintptr_t)front->link ^ (uintptr_t)garbage);
	garbage->link = NULL;
	free(garbage);
}

void rear_Dequeue()
{
	if (rear == nullptr)
	{
		// dqueue is empty;
	}

	DEQUE* garbage = rear;
	rear = (DEQUE*)((uintptr_t)rear->link ^ (uintptr_t)garbage);
	garbage->link = NULL;
	free(garbage);
}