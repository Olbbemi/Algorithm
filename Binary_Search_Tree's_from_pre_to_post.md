# Binary Search Tree's from pre to post

- Binary Search Tree's from pre to post : 이진 탐색트리의 전위순회 정보만으로 후위순회정보를 얻을 수 있음

  - 전위순회 정보는 앞에서부터 매순간 루트를 의미

     ,현재 값보다 큰값이 나오는 위치를 기점으로 좌측은 왼쪽자식노드들, 우측은 오른쪽자식노드들을 의미

~~~c++
queue<int> q;

void Post(int arr[] , int start , int end)
{
	if(start <= end)
	{
		if(start == end)
		{
			q.push(arr[start]);
			return;
		}

		int standard;
		for(standard = start + 1; standard <= end && arr[standard] < arr[start]; standard++);
		
		Post(arr, start + 1, stadnard - 1);
		Post(arr, standard, end);
		q.push(arr[start]);	
	}
}
~~~

