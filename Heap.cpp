/**------------------------------------------------------------------------------------------------------------------------------------------------------------------
  * Min Heap: 모든 부모 노드는 자식 노드들 보다 작은 값을 가짐
  * Max Heap: 모든 부모 노드는 자식 노드들 보다 큰 값을 가짐
  * 힙은 항상 완전이진트리 구조를 만족해야 하며 배열을 이용
  * 시작인덱스를 0부터 시작하면서 현재 노드의 인덱스가 i일 때 해당 노드의 부모 노드 [ (i - 1) / 2 ], 해당 노드의 좌측 자식 노드 [ i * 2 + 1 ], 우측 자식 노드 [ i * 2 + 2 ] 
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