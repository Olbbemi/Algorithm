# Queue

**Queue** : 데이터가 입력되는 순서대로 출력되는 자료구조 (FIFO , LILO)

~~~c
typedef struct _QUEUE
{
	Type data;
	struct _QUEUE * link;
}QUEUE;

void Enqueue( Type D )
{
	QUEUE *temp = (QUEUE*)malloc(sizeof(QUEUE));
	temp->data = D;
	temp->link = NULL;

	if (front == NULL && rear == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->link = temp;
		rear = temp;
	}
}

Data Type Dequeue()
{
	if (front != NULL && rear != NULL)
	{
		Type returnValue = front->data;
		QUEUE *garbage = front;
		front = front->link;

		if (front == NULL)
			rear = NULL;
	}
	else
		/* Error */
}
~~~

