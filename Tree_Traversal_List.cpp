/**-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  *	트리 순회 : 비선형 자료구조의 트리를 구성하는 모든노드를 순차적으로 방문하여 출력 및 작업하는 것을 의미 

  *	순회 방식은 크게 4 가지 방식이 존재 	
		->  전위 탐색 : 루트를 먼저 방문 후 좌측 이동 , 우측 이동 	
			중위 탐색  : 좌측 이동 후 루트 방문 , 우측 이동 [트리의 깊이 정보와 중위 탐색 정보를 이용하면 각 노드를 행렬에 배치 가능 (트리의 깊이: 행, 중위 탐색시 각 노드에 부여하는 번호 : 열)] 
			후위 탐색  : 좌측 이동 후 우측 이동 , 루트 방문 
			레벨 우선 탐색 : 트리는 레벨 구조를 가지며 가장 상위부터 0 으로 시작하여 하위로 갈수록 1씩 증가하는데 이러한 레벨 순서를 이용하여 방문 [ Queue 이용 ]   
  *-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


//PreOrder
void PreOrder(TREE *root) //recursive
{
	if(root != NULL)
	{
		/* print */
		PreOrder(root->Llink);
		PreOrder(root->Rlink);
	}
}

stack<Tree*> s;
void PreOrder(Tree *root) //non-recursive 
{
	while(1)
	{
		while(root != NULL)
		{
			/* print */
			s.push(root);
			root = root->Llink;
		}
		
		if(s.empty() == 1)
			break;
		
		root = s.top()->Rlink;
		s.pop();
	}
}


//InOrder
void InOrder(TREE *root) //recursive 
{
	if(root != NULL)
	{
		InOrder(root->Llink);
		/* print */
		InOrder(root->Rlink);
	}
}

stack<Tree*> s;
void InOrder(Tree *root) //non-recursive 
{
	while(1)
	{
		while(root != NULL)
		{
			s.push(root);
			root = root->Llink;
		}
		
		if(s.empty() == 1)
			break;
		
		root = s.top();	
		s.pop();
		/* print */
		root = root->Rlink;
	}
}


//PostOrder
void PostOrder(TREE *root) //recursive 
{
	if(root != NULL)
	{
		PostOrder(root->Llink);
		PostOrder(root->Rlink);
		/* print */	
	}
}

void PostOrder(TREE *root) //non-recursive
{
	while(1)
	{
		if(root != NULL)
		{
			Push(root);
			root = root->Llink;
		}
		else
		{
			if (s.empty() == 1)
				break;

			if(s.top()->Rlink == NULL)
			{
				root = s.top();
				s.pop();
				/* print */
				
				while(s.empty() != 1 && s.top()->Rlink == root)
				{
					root = s.top();	
					s.pop();
					/* print */
				}
			}
			
			if(s.empty() != 1)
				root = s.top()->Rlink;
			else
				break;
		}
	}
} 

//Level 
queue<TREE*> q;
void Level(TREE *root)
{
	q.push(root);
	while(front != NULL && rear != NULL)
	{
		root = q.front();
		q.pop();
		/* print */
		
		if(root->Llink != NULL)
			q.push(root->Llink);
		
		if(root->Rlink != NULL)
			q.push(root->Rlink);	
	}
}
