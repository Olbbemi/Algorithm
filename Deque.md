# Deque

**Deque**: 양방향 리스트를 사용하며 양 끝에서 데이터의 삽입 및 삭제가 모두 가능

~~~c
typedef struct _DEQUE
{
	int data;
	struct _DEQUE * link;
}DEQUE;

DEQUE * front = NULL , * rear = NULL;

void front_Euqueue(int D)
{
	/*
		malloc 생성 -> DATA 
	*/
	
	if(front == NULL && rear == NULL) 
		front = rear = DATA;
	
	front -> link = (DEQUE*)((uintptr_t)DATA ^ (uintptr_t)front -> link); 
	Data -> link = (DEQUE*)((uintptr_t)front ^ NULL);
	front = Data;
}

void rear_Enqueue(int D)
{
	/*
		malloc 생성 -> DATA 
	*/
	
	if(front == NULL && rear == NULL) 
		front = rear = DATA;
	
	rear -> link = (DEQUE*)((uintptr_t)DATA ^ (uintptr_t)rear -> link); 
	Data -> link = (DEQUE*)((uintptr_t)rear ^ NULL);
	rear = Data;
}

void front_Dequeue()
{
	DEQUE * garbage = front;
	front = front -> link;
	front -> link = (DEQUE*)((uintptr_t)front -> link ^ (uintptr_t)garbage);	
	garbage -> link = NULL;
	free(garbage);
}

void rear_Dequeue()
{
	DEQUE * garbage = rear;
	rear = rear -> link;
	rear -> link = (DEQUE*)((uintptr_t)rear -> link ^ (uintptr_t)garbage);	
	garbage -> link = NULL;
	free(garbage);
}
~~~

