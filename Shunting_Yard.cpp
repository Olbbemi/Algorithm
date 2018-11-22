/*
	shunting yard : ����� ����ϴ� ���� (���� ǥ��) �� ��ǻ�Ͱ� ����ϴ� ���� (���� ǥ��) �� �����ϴ� �˰���

	-> �ǿ����ڴ� ��� �� ��� ť�� ����
	   �����ڴ� Top == NULL �̰ų� Top �� ����Ű�� �������� �켱������ ���� �������� �켱�������� ������ Push , ���ų� ũ�ٸ� Pop
	   '(' [���� ��ȣ] �� ������ Push , ')' [���� ��ȣ] �� ������ '(' [���� ��ȣ] �� ������ ���� ��� �����ڸ� Pop
*/

void postfix(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if(arr[i] != operator)
			/* ��� �� ��� ť�� ���� */
		else
		{
			if (arr[i] == '(')
				Push(arr[i]);
			else if (arr[i] == ')')
			{
				while (Top->data != ')')
					/* Pop() ��� �� ��� ť�� ���� */

				Pop();
			}
			else if (Top == NULL || arr[i]'s priority > Top -> data's priority)
				Push(arr[i]);
			else
			{
				while (arr[i]'s priority <= Top -> data's priority && arr[i] != '(')
					/* Pop() ��� �� ��� ť�� ���� */
			}
		}
	}
}

/*
	����ǥ��� ���� : shunting yard Algorithm �� �̿��Ͽ� ����ǥ������� ��ȯ�� �������̿��Ͽ� ���
	
	-> �ǿ����ڴ� ���ÿ� Push
	   �����ڸ� ������ ���ÿ� �����ϴ� �ǿ����� 2���� Pop [ ���� Pop�ϴ� �����Ͱ� �������� ������ ��ġ ] 
			�����ڸ� �̿��Ͽ� ���� �� �ٽ� ���ÿ� Push 
*/

void postfix_Cacl(char arr[], int size)
{
	for(int i = 0; i < size; i++)	
	{
		if(arr[i] != operator)
			Push(arr[i]);
		else
		{
			int R = Pop(),	L = Pop();
			
			switch(arr[i])
			{
				case '+' :	Push(L + R);	break;
				case '-' :	Push(L - R);	break;				
				case '*' :	Push(L * R);	break;
				case '/' :	Push(L / R);	break;								
			}
		}
	}
	
	/* Pop() ��� �� ��� ť�� ���� */
}
