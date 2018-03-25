# Binary Tree

- **Binary Tree** : 자식노드를 최대 2개 가질 수 있는 트리 [ Binary Tree != Binary search Tree ]

  ,자식노드의 주소를 저장할 포인터 2개를 가짐

  - Insert & Delete : 레벨 우선 탐색을 이용하여 삽입할 위치 탐색 및 삭제할 데이터 탐색



- 이진 트리 :  Lchild 및 Rchild 포인터를 가지며 각각 좌측 자식노드의 주소 , 우측 자식노드의 주소를 저장

~~~c
void General_Insert(int Parent , int Child)
{
	/*
		malloc -> temp;
	*/
	
	if(root == NULL)
		root = temp;
	else
	{
		q.push(root);	
		while(root->data != Parent && q.empty() != 1)
		{
			root = q.front();
			q.pop();
			
			if(root->Lchild != NULL)
				q.push(root->Lchild);
				
			if(root->Rchild != NULL)
				q.push(root->Rchild);
		}
		
		if(q.empty() == 1)
			//Parent isn't exist
			
		if(root->Lchild == NULL)
			root->Lchild = temp;
		else
			root->Rchild = temp;
	}	
}

void General_Delete(int D)
{
	ROOT *temp;
	
	q.push(root);
	while(q.empty() != 1)
	{
		root = q.front();
		q.pop();
		
		if(root->Lchild->data == D)
		{
			temp = root->Lchild;
			root->Lchild = NULL;
			// temp 이하 삭제
			break;
		}
		else
			q.push(root->Lchild);
		
		if(root->Rchild->data == D)
		{
			temp = root->Rchild;
			root->Rchild = NULL;
			// temp 이하 삭제
			break; 
		}
		else
			q.push(root->Rchild);
	}
}
~~~



- M진 트리를 이진 트리로 변환 :  sibling 및 child 포인터를 사용

  , 각 부모노드는 child 포인터를 이용하여 하나의 자식노드 주소만 저장

  , 같은 부모노드를 가지는 자식노드간에는 sibling 포인터를 통해 저장

~~~c
void Convert_Insert(int Parent , int Child)
{
	/*
		malloc -> temp;
	*/
	
	if(root == NULL)
		root = temp;
	else
	{
		q.push(root);		
		while(root->data != Parent && q.empty() != 1)
		{
			root = q.front();
			q.pop();
			
			if(root->Lchild != NULL)
				q.push(root->child);
				
			if(root->Rchild != NULL)
				q.push(root->sibling);
		}
		
		if(q.empty() == 1)
			//Parent isn't exist
			
		if(root->child == NULL)
			root->child = temp;
		else
		{
			root = root->child;
			
			while(root->sibling != NULL)
				root = root->sibling;
				
			root->sibling = temp;
		}
	}	
}

void Convert_Delete(int D)
{
	ROOT *temp;
	
	q.push(root);
	while(q.empty() != 1)
	{
		root = q.front();
		q.pop();
		
		if(root->child != NULL)
		{
			if(root->child->data == D)
			{
				temp = root->child;
				root->child = temp->sibling;
				// temp 이하 삭제
				break; 
			}
		}
		else
			q.push(root->child);
		
		if(root->Rchild != NULL)
		{
			if(root->sibling->data == D)
			{
				temp = root->sibling;
				root->sibling = temp->sibling;
				// temp 이하 삭제
				break;
			}
		}
		else
			q.push(root->sibling);
	}
	
	if(P == NULL)
		// all node delete
	else
	{
		if(P->Lchild == root)
			P->Lchild = NULL;
		else
			P->Rchild = NULL;
	}
}
~~~

