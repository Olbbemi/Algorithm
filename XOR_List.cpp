/**-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  * �Ϲ� ���� ���Ḯ��Ʈ : �ܹ��� ����Ʈ�� �޸� �� ����Ʈ�� ������ �ּҸ� �����ϰ� �־� ��������� Ž���� ������ ����Ʈ ( �� ���� �⺻������ 2���� ������ ������ �������� ) 

  * xor Ư¡ : 1 ^ 1 = 0 
			=> Ư�� ��� �ּ� A , B ���� �� A ^ B ���� A ^ A ^ B �� �ϸ� B �� �ּҸ� ���� [ ����� ���ۿ����� �� ������ �����Ϳ��� NULL ^ �� ��� �ּ� , �� ��� �ּ� ^ NULL �� ���� ]

  * stdint.h ��� ���ϰ� uintptr_t �ڷ����� ����ϸ� ���� �� ���� , Ž���� �Ϲ� ����Ʈ�� ����
  *-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void Insert(int D)
{
	LIST *Cur = Head , *Pre = NULL , temp;
	
	/*
		malloc ���� -> DATA
	*/
	
	// ������ ��� ��嵵 �������� ���� �� 
	if(head == NULL && tail == NULL)
		head = tail = DATA;
	
	// Ư�� ���ǿ� ���� �����͸� ���ϴ� ��ġ�� �ֱ� ���� Ž�� 
	while(Cur->data > D)
	{
		temp = Cur;
		Cur = (LIST*)((uintpre_t)Cur->link ^ (uintpre_t)Pre);
		Pre = temp;
		
		if(Cur == NULL)
			break;
	}
	
	if(Pre == NULL) // ��尡 ���� �տ� ���� ����Ǵ� ��� 
	{
		Data->link = (LIST*)((uintptr_t)head ^ NULL);
		head->link = (LIST*)((uintptr_t)head->link ^ (uintptr_t)Data);
		head = Data;
	}
	
	if(Cur == NULL) // ��尡  ���� �ڿ� ���� ����Ǵ� ��� 
	{
		Pre->link = (LIST*)((uintptr_t)Pre->link ^ (uintptr_t)Data);
		Data->link = (LIST*)((uintptr_t)Pre ^ NULL);
		tail = Data;
	}
	else // ��尡 Ư�� ��� ���̿� ����Ǵ� ��� 
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
		/* ��� */
		temp = Cur;
		Cur = (LIST*)((uintpre_t)Cur->link ^ (uintpre_t)Pre);
		Pre= temp;
	}	
}