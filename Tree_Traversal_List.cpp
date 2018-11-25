/**-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  *	Ʈ�� ��ȸ : ���� �ڷᱸ���� Ʈ���� �����ϴ� ����带 ���������� �湮�Ͽ� ��� �� �۾��ϴ� ���� �ǹ� 

  *	��ȸ ����� ũ�� 4 ���� ����� ���� 	
		->  ���� Ž�� : ��Ʈ�� ���� �湮 �� ���� �̵� , ���� �̵� 	
			���� Ž��  : ���� �̵� �� ��Ʈ �湮 , ���� �̵� [Ʈ���� ���� ������ ���� Ž�� ������ �̿��ϸ� �� ��带 ��Ŀ� ��ġ ���� (Ʈ���� ����: ��, ���� Ž���� �� ��忡 �ο��ϴ� ��ȣ : ��)] 
			���� Ž��  : ���� �̵� �� ���� �̵� , ��Ʈ �湮 
			���� �켱 Ž�� : Ʈ���� ���� ������ ������ ���� �������� 0 ���� �����Ͽ� ������ ������ 1�� �����ϴµ� �̷��� ���� ������ �̿��Ͽ� �湮 [ Queue �̿� ]   
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
