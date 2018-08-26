/**---------------------------------------------------------
  * 데이터가 입력되는 순서대로 출력되는 자료구조 (FIFO , LILO)
  *---------------------------------------------------------*/

struct QUEUE
{
	int data;
	struct QUEUE * link;
};

QUEUE *front, *rear;
void Enqueue(int D)
{
	QUEUE *temp = (QUEUE*)malloc(sizeof(QUEUE));
	temp->data = D;
	temp->link = nullptr;

	if (front == nullptr && rear == nullptr)
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

int Dequeue()
{
	if (front != nullptr && rear != nullptr)
	{
		int return_value = front->data;
		QUEUE *garbage = front;
		front = front->link;

		if (front == nullptr)
			rear = nullptr;

		free(garbage);
		return return_value;
	}
	else
	{
		// queue is empty;
	}
}