/**-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  * 일반 이중 연결리스트 : 단방향 리스트와 달리 두 리스트가 서로의 주소를 저장하고 있어 양방향으로 탐색이 가능한 리스트 ( 한 노드당 기본적으로 2개의 포인터 변수를 가져야함 ) 

  * xor 특징 : 1 ^ 1 = 0 
			=> 특정 노드 주소 A , B 존재 시 A ^ B 에서 A ^ A ^ B 를 하면 B 의 주소만 존재 [ 노드의 시작영역과 끝 영역의 포인터에는 NULL ^ 뒷 노드 주소 , 앞 노드 주소 ^ NULL 이 저장 ]

  * stdint.h 헤더 파일과 uintptr_t 자료형을 사용하며 삽입 및 삭제 , 탐색은 일반 리스트와 동일
  *-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void Insert(int D)
{
	LIST *Cur = Head , *Pre = NULL , temp;
	
	/*
		malloc 생성 -> DATA
	*/
	
	// 이전에 어떠한 노드도 존재하지 않을 때 
	if(head == NULL && tail == NULL)
		head = tail = DATA;
	
	// 특정 조건에 따라 데이터를 원하는 위치에 넣기 위한 탐색 
	while(Cur->data > D)
	{
		temp = Cur;
		Cur = (LIST*)((uintpre_t)Cur->link ^ (uintpre_t)Pre);
		Pre = temp;
		
		if(Cur == NULL)
			break;
	}
	
	if(Pre == NULL) // 노드가 가장 앞에 새로 연결되는 경우 
	{
		Data->link = (LIST*)((uintptr_t)head ^ NULL);
		head->link = (LIST*)((uintptr_t)head->link ^ (uintptr_t)Data);
		head = Data;
	}
	
	if(Cur == NULL) // 노드가  가장 뒤에 새로 연결되는 경우 
	{
		Pre->link = (LIST*)((uintptr_t)Pre->link ^ (uintptr_t)Data);
		Data->link = (LIST*)((uintptr_t)Pre ^ NULL);
		tail = Data;
	}
	else // 노드가 특정 노드 사이에 연결되는 경우 
	{
		Pre->link = (LIST*)((uintptr_t)Pre->link ^ (uintptr_t)Cur ^ (uintptr_t)Data);
		Cur->link = (LIST*)((uintptr_t)Cur->link ^ (uintptr_t)Pre ^ (uintptr_t)Data);
		Data->link = (LIST*)((uintptr_t)Cur ^ (uintptr_t)Pre);
	}
}

void Delete(int D)
{
	LIST *Cur = head , *Pre = NULL , temp;
	
	while(Cur->data != D)
	{
		temp = Cur;
		Cur = (LIST*)((uintpre_t)Cur->link ^ (uintpre_t)Pre);
		Pre = temp;
	}
	
	if(Cur == head)
	{
		Pre = Cur;	Cur = Cur->link;
		Cur->link = (LIST*)((uintpre_t)Cur->link ^ (uintpre_t)Pre ^ NULL);
		Pre->link = NULL;
		head = Cur;
		free(Pre);	
	}
	else if(Cur == tail)
	{
		Pre->link = (LIST*)((uintpre_t)Pre->link ^ (uintpre_t)Cur ^ NULL);
		Cur->link = NULL;
		tail = Pre;
		free(Cur);
	}
	else
	{
		temp = Cur;
		Cur = (LIST*)((uintpre_t)Cur -> link ^ (uintpre_t)Pre);
		Pre->link = (LIST*)((uintpre_t)Pre->link ^ (uintpre_t)temp ^ (uintpre_t)Cur);
		Cur->link = (LIST*)((uintpre_t)Cur->link ^ (uintpre_t)temp ^ (uintpre_t)Pre);
		temp->link = NULL;
		free(temp);
	}
}

void Traversal()
{
	LIST *Cur = head , *Pre = NULL , temp;
	
	while(Cur != NULL)
	{
		/* 출력 */
		temp = Cur;
		Cur = (LIST*)((uintpre_t)Cur->link ^ (uintpre_t)Pre);
		Pre= temp;
	}	
}