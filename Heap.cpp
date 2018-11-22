/**------------------------------------------------------------------------------------------------------------------------------------------------------------------
  * Min Heap: ��� �θ� ���� �ڽ� ���� ���� ���� ���� ����
  * Max Heap: ��� �θ� ���� �ڽ� ���� ���� ū ���� ����
  * ���� �׻� ��������Ʈ�� ������ �����ؾ� �ϸ� �迭�� �̿�
  * �����ε����� 0���� �����ϸ鼭 ���� ����� �ε����� i�� �� �ش� ����� �θ� ��� [ (i - 1) / 2 ], �ش� ����� ���� �ڽ� ��� [ i * 2 + 1 ], ���� �ڽ� ��� [ i * 2 + 2 ] 
  *------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void M_Push(DATA_TYPE pa_data)
{
	if (m_size == 0)
		m_array[0] = pa_data;
	else
	{
		int lo_index = m_size;
		while (lo_index != 0 && m_array[(lo_index - 1) / 2] > pa_data)
		{
			m_array[lo_index] = m_array[(lo_index - 1) / 2];
			lo_index = (lo_index - 1) / 2;
		}

		m_array[lo_index] = pa_data;
	}

	m_size++;
}

void M_Pop(DATA_TYPE pa_value)
{
	if (m_size == 0)
		return;

	int lo_parent = 0, lo_child = 1;
	DATA_TYPE lo_comp = m_array[--m_size];

	pa_value = m_array[0];

	while (lo_child < m_size)
	{
		if (lo_child < m_size - 1 && m_array[lo_child] > m_array[lo_child + 1])
			lo_child++;

		if (lo_comp > m_array[lo_child])
		{
			m_array[lo_parent] = m_array[lo_child];
			lo_parent = lo_child;
			lo_child = lo_child * 2 + 1;
		}
		else
			break;
	}

	m_array[lo_parent] = lo_comp;
}