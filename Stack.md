# Stack

**Stack** : 가장 마지막에 입력된 데이터가 가장 먼저 출력되는 자료구조 (LIFO, FILO)

```c
typedef struct _STACK
{
	Type data;
	struct _STACK * link;
};

Data Type Pop()
{
	if (Top != NULL)
	{
		Type returnValue = Top->data;
		STACK * garbage = Top;
		Top = Top->link;
		free(grabage);
		return returnValue;
	}
	else
		/* Error */
}

 void Push( Type D )
 {
	STACK * temp = (STACK*)malloc(sizeof(STACK));
	temp->data = D;
	temp->link = Top;
	Top = temp;
 } 
```
