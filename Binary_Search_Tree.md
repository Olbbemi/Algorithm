# Binary Search Tree

- **Binary Search Tree** : 이진트리에서 확장된 개념으로 루트를 기준으로 좌측은 루트보다 작은 값 

  ​	,우측은 루트보다 큰 값을 저장

- Insert : Binary Search Tree 정의에 맞게 삽입 

- Delete

  1. 삭제 노드의 자식노드 0 개 : 삭제노드가 루트의 좌측에 존재하면 좌측 포인터를 NULL 

     ​	, 우측에 존재하면 우측 포인터를 NULL

  2. 삭제 노도의 자식노드 1 개 : 삭제노드가 가지는 자식노드의 위치와 부모노드에서 

     ​	해당 삭제노드가 위치한 포인터를 매칭 

  3. 삭제 노드의 자식노드 2 개 : 삭제노드를 기준으로 좌측 자식노드에서 가장 우측에 위치한 노드와 

     ​	우측 자식노드에서 가장 좌측에 위차한 노드를 비교하여 루트와의 차가 더 작은 값을 이동
     	[ 해당 코드에서는 좌측 자식노드에서 가장 우측에 위치한 노드를 이동 ]

~~~c
void Insert(int D)
{
	ROOT * temp = (ROOT*)malloc(sizeof(ROOT));
	temp->data = D;
	temp->Llink = temp->Rlink = NULL;

	if (root == NULL)
		root = temp;
	else
	{
		ROOT * Child = root, *Parent = NULL;

		while (Child != NULL)
		{
			Parent = Child;

			if (Child->data > D)
				Child = Child->Llink;
			else
				Child = Child->Rlink;
		}

		if (Parent->data > D)
			Parent->Llink = temp;
		else
			Parent->Rlink = temp;
	}
}

void Delete(int D)
{
	ROOT *Child = root, *Parent = NULL, *LPT, *LCT;

	while (Child->data != D)
	{
		Parent = Child;

		if (Child->data < D)
			Child = Child->Rlink;
		else
			Child = Child->Llink;
	}

	if (Child->Llink == NULL && Child->Rlink == NULL)
	{
		if (Parent->Llink == Child)
			Parent->Llink = NULL;
		else
			Parent->Rlink = NULL;

		Child->Llink = Child->Rlink = NULL;
		free(Child);
	}
	else if (Child->Llink != NULL && Child->Rlink == NULL 
             || Child->Llink == NULL && Child->Rlink != NULL)
	{
		if (Child->Llink != NULL && Child->Rlink == NULL)
		{
			if (Parent->Llink == Child)
				Parent->Llink = Child->Llink;
			else
				Parent->Rlink = Child->Llink;
		}
		else
		{
			if (Parent->Llink == Child)
				Parent->Llink = Child->Rlink;
			else
				Parent->Rlink = Child->Rlink;
		}

		Child->Llink = Child->Rlink = NULL;
		free(Child);
	}
	else if(Child->Llink != NULL && Child->Rlink != NULL)
	{
		LPT = Child->Llink;	LCT = Child->Llink->Rlink;

		if (LCT == NULL)
		{
			Child->data = LPT->data;
			Child->Llink = LPT->Llink;
			LPT->Llink = LPT->Rlink = NULL;
			free(LPT);
		}
		else
		{
			while (LCT->Rlink != NULL)
			{
				LPT = LCT;
				LCT = LCT->Rlink;
			}

			Child->data = LCT->data;
			LPT->Rlink = LCT->Llink;
			LCT->Llink = LCT->Rlink = NULL;
			free(LCT);
		}
	}
}
~~~