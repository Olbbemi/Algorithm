/**---------------------------------------------------------------------------------------------------------------------
  * Heap �ڷᱸ���� �����̹Ƿ� Heap �ڷᱸ���� ������ ������ ������ ����

  * Min_Heap ���� ���� ū ��ġ�� ã�� �ð� (N), Max_Heap ���� ���� ���� ��ġ�� ã�� �ð� (N)
		-> �� ������ �����ϰ��� ���� �ڷᱸ�� [ ���� ���� ��ġ ã�� �ð� (1), ���� ū ��ġ ã�� �ð� (1) ]

  * Ʈ���� ¦�� ������ Min_Level, Ȧ�� ������ Max_Level
  * ���� �����Ͱ� Min_Level �̸鼭 �θ𺸴� ū ���   -> �θ� �����͸� ���� ��ġ�� ����, Max_Insert �Լ� ȣ�� [ �θ� �ε��� ]
  * ���� �����Ͱ� Min_Level �̸鼭 �θ𺸴� ���� ��� -> Min_Insert �Լ� ȣ�� [ ���� �ε��� ]
  * ���� �����Ͱ� Max_Level �̸鼭 �θ𺸴� ū ���   -> Max_Insert �Լ� ȣ�� [ ���� �ε��� ]
  * ���� �����Ͱ� Max_Level �̸鼭 �θ𺸴� ���� ��� -> �θ� �����͸� ���� ��ġ�� ����, Min_Insert �Լ� ȣ�� [ �θ� �ε��� ]
		-> Min_Insert �� Max_Insert �Լ��������� ���谡 �θ�� �ڽ��� �ƴ� ����� �ڼ��̹Ƿ� / 4 �� �̿�

  * ���� ���� ��ġ�� 1�� �ε����� ��ġ, ���� ū ��ġ�� 2�� �Ǵ� 3�� �ε����� ��ġ
  * �ڽĳ��� ���� �� �� �ڼճ��� �� ( index �� -1�� ��Ȳ�� Ȯ���ϴ� ������ ���� �����Ͱ� �����ϴ� ��츦 Ȯ�� )
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