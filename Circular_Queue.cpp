/**-----------------------------
  * Linear Queue ������: pop�� �ϸ� front�� �̵��ϸ鼭 ���� �迭 ������ ��� �� �� ����
  * Circular Queue : % ������ �̿��Ͽ� �������� �迭�� ���۰� ���� ����
  * front , rear �� 0 ���� �ʱ�ȭ
  * front == rear �̸� Emtpy ����
  * (rear + 1) % N == front �̸� Full ����
  * �迭 ��ü ũ�Ⱑ N �̸� �ִ� ������ �� �ִ� ������ ������ N - 1 [ Full �� Empty �� �����ϱ�����]
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