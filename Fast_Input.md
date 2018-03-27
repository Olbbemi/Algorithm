# Fast Input

- 입력 함수 빠르기 비교 ( 빠르기와 안정성은 반비례 )

  - getchar_unlocked() > getchar > scanf > cin

    ​

- getchar_unlocked() 함수는 getchar()에서 mutual_exclusion 을 배제한 함수

   빠르기는 getchar() 함수보다 빠르지만 안정성은 떨어짐

  ​


- getchar_unlocked()

~~~
int input()
{
	bool flag = false;
	char in;
	int cal = 0;
	
	in = getchar_unlocked();
	while(in < '0' || in > '9')
	{
		if(in == '-')
			flag = true;
			
		in = getchar_unlocked();
	}
	
	while(in >= '0' && in <= '9')
	{
		cal = cal * 10 + (in - 48); // cal = (cal << 3) + (cal << 1) + (in - 48);
		in = getchar_unlocked();
	}
	
	if(flag == true)
		cal = ~cal + 1; // ~ 연산자는 1의 보수를 취하는 연산자이므로 2의 보수값을 얻기위해서는 + 1을 해주어야 함 
	
	return cal
}
~~~



- fread()

~~~
char buf[MAX]; // MAX 범위는 임의적으로 정할 수 있음 
int inputIndex = 0 , curIndex = 0;

static inline char read()
{
	if (inputIndex == curIndex)
	{
		inputIndex = fread(buf, 1, MAX, stdin);
		curIndex = 0;
	}

	return buf[curIndex++];
}

int readInt()
{
	bool flag = false;
	char input;
	int sum = 0;
	
	input = read();
	while (input < '0' || input > '9')
	{
		if (input == '-')	
			flag = true;
			
		input = read();
	}

	while (input >= '0' && input <= '9')
	{
		sum = (sum << 3) +(sum << 1) + (input - 48);
		input = read();
	}

	if(flag == true)
		sum = ~sum + 1;

	return sum;
}
~~~