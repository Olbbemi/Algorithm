/**---------------------------------------------------------------------------------------------------------------------------------------------------
  * Tree Traversal Array : �迭�� �̿��Ͽ� Ʈ���� ����, ����, ���� ��ȸ������ ��� 
		-> �����Ͱ� �ε��� 1������ ����� ��� : �ڽĳ��� �θ��� * i [ �����ڽ� ], �θ��� * i + 1 [ �������ڽ� ], �θ���� �ڽĳ�� / 2 
		   �����Ͱ� �ε��� 0������ ����� ��� : �ڽĳ��� �θ��� * i + 1 [ �����ڽ� ], �θ��� * i + 2 [ �������ڽ� ], �θ���� ( �ڽĳ�� - 1 ) / 2	

  *	���� Ž�� : ��Ʈ�� ���� �湮 �� ���� �̵� , ���� �̵� 		
  *	���� Ž��  : ���� �̵� �� ��Ʈ �湮 , ���� �̵� 
  *	���� Ž��  : ���� �̵� �� ���� �̵� , ��Ʈ �湮    
  *---------------------------------------------------------------------------------------------------------------------------------------------------*/

//PreOrder
void PreOrder(int arr[] , int start , int size)
{
	if(start <= size)
	{
		/* print */
		PreOrder(arr,start * 2, size);	
		PreOrder(arr,start * 2 + 1, size);	
	}
}

//InOrder
void InOrder(int arr[] , int start , int size)
{
	if(start <= size)
	{
		InOrder(arr,start * 2, size);	
		/* print */
		InOrder(arr,start * 2 + 1, size);	
	}
}

//PostOrder
void PostOrder(int arr[] , int start , int size)
{
	if(start <= size)
	{	
		PostOrder(arr,start * 2, size);	
		PostOrder(arr,start * 2 + 1, size);	
		/* print */
	}
}
