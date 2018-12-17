/**---------------------------------------------------------------------------------------------------------------------
  * lower_bound : ���ĵǾ� �ִ� ���� �迭���� �־��� ���� �ԷµǾ ������ ������ �ʴ� ��ġ, �־��� ���� ������ �����͵� ���� 
  * upper_bound : ���ĵǾ� �ִ� ���� �迭���� �־��� ���� �ԷµǾ ������ ������ �ʴ� ��ġ, �־��� ���� ������ ������ ������ 
  *---------------------------------------------------------------------------------------------------------------------*/

int Lower_Bound(int A[], int s, int e, int data)
{
	while (s < e)
	{
		int mid = (s + e) >> 1;

		if (A[mid] < data)
			s = m + 1; 
		else
			e = m;
	}

	return e;
}

int Upper_Bound(int A[], int s, int e, int data)
{
	while (s < e)
	{
		int mid = (s + e) >> 1;

		if (A[mid] <= data)
			s = m + 1; 
		else
			e = m;
	}

	return e;
}