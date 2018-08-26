/**-------------------------
  * ����� ����Ʈ�� ����ϸ� �� ������ �������� ���� �� ������ ��� ������ �ڷᱸ��
  * ������ ������ Xor �����ڸ� ���Ͽ� �ܹ��� ����Ʈ������ ��������� �̵������� ���� ��� 
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