/*
	Selection Algorithm : 배열 내부에서 N 번째 작은 수 및 큰 수를 찾는 알고리즘 

	-> 퀵 정렬과 유사하게 특정 피벗을 선택 후 피벗을 기준으로 좌측은 피벗보다 작은 값 (Small group) 우측은 피벗보다 큰 값 (Big group) 으로 분류
		Small Group + 1 이 현재 피벗이 위치한 K 번째 작은 수를 의미
				
		1. N == K + 1 이면 => 배열 [pivot] 반환
		2. N > K + 1 이면  => 재귀 호출 ( pivot + 1 , end , N - Small Group - 1 ) // -1 의미는 피벗 또한 제외 
									[ Big Group 에서는 이미 start ~ pivot 사이는 해당 수가 존재하지 않는 것을 알기 때문에 pivot - start + 1 개수만큼은 무시 ] 
		3. N < K + 1 이면 => 재귀 호출 ( start , pivot - 1 , N ) 
				
	- nth_element(배열의 시작, 정렬 기준 위치, 배열의 끝) : selection Algorithm 과 유사한 역할을 하는 함수 
*/
 
 int Selection(int arr[] , int start , int end , int key)
 {
 	int pivot , standard , L , R , Small_Size:
 	
 	pivot = arr[start];
 	L = start;	R = end;
 	
 	while(start < end)
 	{
 		while(pivot <= arr[end] && start < end) end--;
		 
		if(start != end)	
 			arr[start++] = arr[end];
 			
 		while(pivot >= arr[end] && start < end) start++;
		 
		if(start != end)	
 			arr[end--] = arr[start];
	}
 		
 	arr[start] = pivot;
 	standard = start;
 	start = L;	end = R;
 	
 	Small_Size = standard - start + 1;
 	
 	if(Small_size == key)
 		return arr[standard];
 	else if(Small_size > key)
 		Selection(arr , start , standard - 1 , key);
 	else if(Small_Size < key)
 		Selection(arr,standard + 1 , end , key - Small_size);
 }
