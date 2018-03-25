# Binary Search Tree's from post to Pre

- Binary Search Tree's from post to Pre : 이진 탐색트리의 후위순회 정보만으로 전위순회정보를 얻을 수 있음 

  -  후위순회 정보는 뒤에서부터 매순간 루트를 의미 [Post 와 Pre 의 루트 시점이 반대] 

    ,현재 값보다 작은값이 나오는 위치를 기점으로 좌측은 왼쪽자식노드들, 우측은 오른쪽자식노드들을 의미

~~~c++
stack<int> s;

// 초기 end : size - 1
void Pre(int arr[] , int start , int end)  
{
	if(start <= end)
	{
		if(start == end)
		{
			s.push(arr[end]);
			return;
		}
		
		int standard;
		for(standard = end - 1; standard >= start && arr[standard] > arr[end]; standard--);
		
		s.push(arr[end]);
		Pre(arr, start, stadnard);
		Pre(arr,  stadnard + 1, end - 1);
	}
}
~~~





