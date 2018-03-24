# Round Algorithm

1. pow 함수를 이용하여 원하는 자리수까지 정수로 변경

2. 해당 수에 0.5 를 더함 

3.  floor() 함수를 통해 소수점 이하를 모두 버림

4. pow 함수를 이용하여 곱한 자리수만큼 다시 나누어 줌

  ​

~~~
double Round(double data , int pivot)
{
	data *= pow(10,pivot);
	data += 0.5;
	data = floor(data); 
	data /= pow(10,pivot); 
	
	return data;
}
~~~

