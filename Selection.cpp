/*
	Selection Algorithm : �迭 ���ο��� N ��° ���� �� �� ū ���� ã�� �˰��� 

	-> �� ���İ� �����ϰ� Ư�� �ǹ��� ���� �� �ǹ��� �������� ������ �ǹ����� ���� �� (Small group) ������ �ǹ����� ū �� (Big group) ���� �з�
		Small Group + 1 �� ���� �ǹ��� ��ġ�� K ��° ���� ���� �ǹ�
				
		1. N == K + 1 �̸� => �迭 [pivot] ��ȯ
		2. N > K + 1 �̸�  => ��� ȣ�� ( pivot + 1 , end , N - Small Group - 1 ) // -1 �ǹ̴� �ǹ� ���� ���� 
									[ Big Group ������ �̹� start ~ pivot ���̴� �ش� ���� �������� �ʴ� ���� �˱� ������ pivot - start + 1 ������ŭ�� ���� ] 
		3. N < K + 1 �̸� => ��� ȣ�� ( start , pivot - 1 , N ) 
				
	- nth_element(�迭�� ����, ���� ���� ��ġ, �迭�� ��) : selection Algorithm �� ������ ������ �ϴ� �Լ� 
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
