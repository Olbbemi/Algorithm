/**----------------------------------------------------------------------------------------------------------
  * Bianry Search: 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘

  * Arr: 정렬된 리스트, Data: 현재 찾는값, mid: (start + end) / 2 일 때 

		- if(Arr[mid] == Data) -> mid 위치에 존재하는 값이 찾고자 하는 데이터의 위치
		- if(Arr[mid] > Data)  -> mid 위치에 존재하는 값이 찾고자 하는 데이터보다 큰 경우   => end = mid - 1;
		- if(Arr[mid] < Data)  -> mid 위치에 존재하는 값이 찾고자 하는 데이터보다 작은 경우 => start = mid + 1;
  *----------------------------------------------------------------------------------------------------------*/

int Binary_Search(int start, int end, int key)
{
	while (start <= end)
	{
		int mid = (start + end) >> 1;

		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
			end = mid - 1;
		else if (arr[mid] < key)
			start = mid + 1;
	}

	return -1; // 해당 데이터가 없음
}