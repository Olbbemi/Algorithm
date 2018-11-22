/*
	shunting yard : 사람이 사용하는 수식 (중위 표기) 를 컴퓨터가 사용하는 수식 (후위 표기) 로 변경하는 알고리즘

	-> 피연산자는 출력 및 출력 큐에 삽입
	   연산자는 Top == NULL 이거나 Top 이 가리키는 데이터의 우선순위가 현재 데이터의 우선순위보다 낮으면 Push , 같거나 크다면 Pop
	   '(' [열린 괄호] 를 만나면 Push , ')' [닫힌 괄호] 를 만나면 '(' [열린 괄호] 를 만날때 까지 모든 연산자를 Pop
*/

void postfix(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if(arr[i] != operator)
			/* 출력 및 출력 큐에 삽입 */
		else
		{
			if (arr[i] == '(')
				Push(arr[i]);
			else if (arr[i] == ')')
			{
				while (Top->data != ')')
					/* Pop() 출력 및 출력 큐에 삽입 */

				Pop();
			}
			else if (Top == NULL || arr[i]'s priority > Top -> data's priority)
				Push(arr[i]);
			else
			{
				while (arr[i]'s priority <= Top -> data's priority && arr[i] != '(')
					/* Pop() 출력 및 출력 큐에 삽입 */
			}
		}
	}
}

/*
	후위표기식 연산 : shunting yard Algorithm 을 이용하여 후위표기식으로 변환한 수식을이용하여 계산
	
	-> 피연산자는 스택에 Push
	   연산자를 만나면 스택에 존재하는 피연산자 2개를 Pop [ 먼저 Pop하는 데이터가 연산자의 우측에 위치 ] 
			연산자를 이용하여 연산 후 다시 스택에 Push 
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
	
	/* Pop() 출력 및 출력 큐에 삽입 */
}
