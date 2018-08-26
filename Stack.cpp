/**--------------------------------------------------------------------
  * 가장 마지막에 입력된 데이터가 가장 먼저 출력되는 자료구조 (LIFO, FILO)
  *--------------------------------------------------------------------*/

struct STACK
{
	int data;
	struct STACK* link;
};

STACK* Top = nullptr;
int Pop()
{
	if (Top != nullptr)
	{
		int returnValue = Top->data;
		STACK* garbage = Top;
		Top = Top->link;
		free(grabage);
		return returnValue;
	}
	else
	{
		// stack is empty;
	}
}

void Push(int D)
{
	STACK * new_node = (STACK*)malloc(sizeof(STACK));
	new_node->data = D;
	new_node->link = Top;
	Top = new_node;
}