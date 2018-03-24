# GCD_LCM

- **GCD** : 두 정수의 약수 중 가장 큰 공통약수
- **LCM** : 두 정수(A, B) 를 최대공약수로 나눈 나머지(a, b) 와 최대공약수의 곱 [a 와 b 는 서로소]

	유클리드 알고리즘 : GCD(A, B) = GCD(B, A % B)
	
		A = aG, B = bG [G: 최대공약수] (a와 b는 서로소)
	
		A를 B로 나눈 몫을 Q, 나머지를 R 정의할 때 
			-> A = Q * B + R
	
		R = A - (Q * B) = aG - (Q * bG) = (a - bQ) * G	
		R = (a - bQ) * G, B = b * G
			-> a - bQ와 b 가 서로소임을 증명하면 됨
	
		귀류법: a - bQ와 b는 서로소가 아님으로 가정 
			-> a - bQ = n * P, b = m * P
	
		a = (mQ + n) * p
		b = m * P
	
			-> a와 b는 이미 서로소임이 증명되었으므로 해당 증명은 거짓, a - bQ와 b는 서로소


~~~c
int gcd(int a , int b)
{
	if(b == 0)	
		return a;
	else 
		gcd(b , a % b);	
}

int gcd(int a , int b)
{
	int temp;
	
	while(b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	
	return a;
}
~~~