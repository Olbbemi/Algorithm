/**---------------------------------------------------------------------------------------------------------------------------------------------------
  * Tree Traversal Array : 배열을 이용하여 트리의 전위, 중위, 후위 순회정보를 출력 
		-> 데이터가 인덱스 1번부터 저장된 경우 : 자식노드는 부모노드 * i [ 왼쪽자식 ], 부모노드 * i + 1 [ 오른쪽자식 ], 부모노드는 자식노드 / 2 
		   데이터가 인데스 0번부터 저장된 경우 : 자식노드는 부모노드 * i + 1 [ 왼쪽자식 ], 부모노드 * i + 2 [ 오른쪽자식 ], 부모노드는 ( 자식노드 - 1 ) / 2	

  *	전위 탐색 : 루트를 먼저 방문 후 좌측 이동 , 우측 이동 		
  *	중위 탐색  : 좌측 이동 후 루트 방문 , 우측 이동 
  *	후위 탐색  : 좌측 이동 후 우측 이동 , 루트 방문    
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
