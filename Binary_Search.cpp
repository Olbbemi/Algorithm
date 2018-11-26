/**----------------------------------------------------------------------------------------------------------
  * Bianry Search: ���ĵ� ����Ʈ���� Ư���� ���� ��ġ�� ã�� �˰���

  * Arr: ���ĵ� ����Ʈ, Data: ���� ã�°�, mid: (start + end) / 2 �� �� 

		- if(Arr[mid] == Data) -> mid ��ġ�� �����ϴ� ���� ã���� �ϴ� �������� ��ġ
		- if(Arr[mid] > Data)  -> mid ��ġ�� �����ϴ� ���� ã���� �ϴ� �����ͺ��� ū ���   => end = mid - 1;
		- if(Arr[mid] < Data)  -> mid ��ġ�� �����ϴ� ���� ã���� �ϴ� �����ͺ��� ���� ��� => start = mid + 1;
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

	return -1; // �ش� �����Ͱ� ����
}