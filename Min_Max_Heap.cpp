/**---------------------------------------------------------------------------------------------------------------------
  * Heap 자료구조의 변형이므로 Heap 자료구조가 가지는 성질은 무조건 성립

  * Min_Heap 에서 가장 큰 수치를 찾는 시간 (N), Max_Heap 에서 가장 작은 수치를 찾는 시간 (N)
		-> 위 단점을 보완하고자 나온 자료구조 [ 가장 작은 수치 찾는 시간 (1), 가장 큰 수치 찾는 시간 (1) ]

  * 트리의 짝수 레벨은 Min_Level, 홀수 레벨은 Max_Level
  * 현재 데이터가 Min_Level 이면서 부모보다 큰 경우   -> 부모 데이터를 현재 위치에 복사, Max_Insert 함수 호출 [ 부모 인덱스 ]
  * 현재 데이터가 Min_Level 이면서 부모보다 작은 경우 -> Min_Insert 함수 호출 [ 현재 인덱스 ]
  * 현재 데이터가 Max_Level 이면서 부모보다 큰 경우   -> Max_Insert 함수 호출 [ 현재 인덱스 ]
  * 현재 데이터가 Max_Level 이면서 부모보다 작은 경우 -> 부모 데이터를 현재 위치에 복사, Min_Insert 함수 호출 [ 부모 인덱스 ]
		-> Min_Insert 및 Max_Insert 함수내에서는 관계가 부모와 자식이 아닌 조상과 자손이므로 / 4 를 이용

  * 가장 작은 수치는 1번 인덱스에 위치, 가장 큰 수치는 2번 또는 3번 인덱스에 위치
  * 자식노드와 먼저 비교 후 자손노드와 비교 ( index 가 -1인 상황을 확인하는 이유는 같은 데이터가 존재하는 경우를 확인 )
  *---------------------------------------------------------------------------------------------------------------------*/

#define MIN 0
#define MAX 1

int level(int size)
{
	int lo_count = log2(size);

	if ((lo_count & 1) == 0)
		return MIN;
	else
		return MAX;
}

void Insert(int pa_data)
{
	int lo_parent = (++m_size) / 2;

	if (lo_parent == 0)
		Array[1] = pa_data;
	else
	{
		if (level(m_size) == MIN)
		{
			if (pa_data > Array[lo_parent])
			{
				Array[m_size] = Array[lo_parent];
				Insert_lo_max(lo_parent, pa_data);
			}
			else
				Insert_lo_min(m_size, pa_data);
		}
		else
		{
			if (pa_data < Array[lo_parent])
			{
				Array[m_size] = Array[lo_parent];
				Insert_lo_min(lo_parent, pa_data);
			}
			else
				Insert_lo_max(m_size, pa_data);
		}
	}
}

void Insert_lo_min(int lo_parent, int pa_data)
{
	while (lo_parent != 1 && pa_data < Array[lo_parent / 4])
	{
		Array[lo_parent] = Array[lo_parent / 4];
		lo_parent /= 4;
	}

	Array[lo_parent] = pa_data;
}

void Insert_lo_max(int lo_parent, int pa_data)
{
	while ((lo_parent != 2 && lo_parent != 3) && pa_data > Array[lo_parent / 4])
	{
		Array[lo_parent] = Array[lo_parent / 4];
		lo_parent /= 4;
	}

	Array[lo_parent] = pa_data;
}

void Delete_lo_min()
{
	int lo_temp, lo_index;
	int lo_min;

	if (m_size == 0)
		return;

	Array[1] = Array[m_size--];
	if (m_size == 0)
		return;

	lo_temp = 1;
	while (1)
	{
		lo_index = -1;
		lo_min = Array[lo_temp]; 

		if (lo_temp * 2 > m_size)
			break;
		else
		{
			for (int i = 0; i < 2; i++)
			{
				if (lo_temp * 2 + i > m_size)
					break;

				if (Array[lo_temp * 2 + i] < lo_min)
				{
					lo_min = Array[lo_temp * 2 + i];
					lo_index = lo_temp * 2 + i;
				}
			}

			if (lo_index != -1)
				swap(Array[lo_temp], Array[lo_index]);
		}

		lo_index = -1;
		lo_min = Array[lo_temp]; 

		if (lo_temp * 4 > m_size)
			break;
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (lo_temp * 4 + i > m_size)
					break;
				else
				{
					if (lo_min > Array[lo_temp * 4 + i])
					{
						lo_min = Array[lo_temp * 4 + i];
						lo_index = lo_temp * 4 + i;
					}
				}
			}

			if (lo_index != -1)
			{
				swap(Array[lo_temp], Array[lo_index]);
				lo_temp = lo_index;
			}
			else
				break;
		}
	}
}

void Delete_lo_max()
{
	int lo_temp, lo_index;
	int lo_max;

	if (m_size == 0)
		return;

	if (m_size == 1)
	{
		m_size--;
		return;
	}

	if (Array[2] > Array[3])
	{
		Array[2] = Array[m_size];
		lo_temp = 2;
	}
	else
	{
		Array[3] = Array[m_size];
		lo_temp = 3;
	}

	m_size--;
	while (1)
	{
		lo_index = -1;
		lo_max = Array[lo_temp]; 

		if (lo_temp * 2 > m_size)
			break;
		else
		{
			for (int i = 0; i < 2; i++)
			{
				if (lo_temp * 2 + i > m_size)
					break;

				if (lo_max < Array[lo_temp * 2 + i])
				{
					lo_max = Array[lo_temp * 2 + i];
					lo_index = lo_temp * 2 + i;
				}
			}

			if (lo_index != -1)
				swap(Array[lo_temp], Array[lo_index]);
		}

		lo_index = -1;
		lo_max = Array[lo_temp]; 

		if (lo_temp * 4 > m_size)
			break;
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (lo_temp * 4 + i > m_size)
					break;
				else
				{
					if (lo_max < Array[lo_temp * 4 + i])
					{
						lo_max = Array[lo_temp * 4 + i];
						lo_index = lo_temp * 4 + i;
					}
				}
			}

			if (lo_index != -1)
			{
				swap(Array[lo_temp], Array[lo_index]);
				lo_temp = lo_index;
			}
			else
				break;
		}
	}
}