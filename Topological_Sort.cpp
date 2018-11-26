/**---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  * DAG : ���⼺�� ������ ����Ŭ�� �������� �ʴ� �׷��� [Directed Acyclic Graph] 
  * Topological Sort : �۾��� ������ ������ ���� �� ������ �°� �����ϴ� �˰����� 
		- Indegree : Ư�� �������� ������ ���� 
		- Outdegree : Ư�� �������� ������ ���� 
	
		=> Indegree �� 0 �� �������� ��� queue �� �Է� �� �׷��� ������ �̿��Ͽ� BFS Ž��
			(BFS �� �����ϳ� �湮�� ������ �ƴ� Indegree ������ 0 �̸� queue �� �Է��ϴ� ���) 

  * CPM : �۾��� ���� �� ��� �ð��� �־��� �� ��� �۾��� �����ϴµ� �ʿ��� �ּ����� �ð��� ���ϴ� �˰�����
			, ���������� �̿��ϸ� �� ���������� �ִ밪�� ���� 
  
  * Critical Path: ��ü �۾� �� ���� �����Ⱓ�� ����ϴ� �۾� ���
		- ���������� �̿��Ͽ� �� ������ ���� �ִ밪 [Store] �� ����
		- ���� �׷����� ������ �ݴ�� ������ �׷����� ����
		- �� ������ Store ���� ���������� ���� ����ġ�� �������� ������ �ش� ��δ� ���� x
		- �� ������ Store ���� ���������� ���� ����ġ�� �����ϸ鼭 �� ���� �� ���������� ��ο� ���ԵǴ� �����̸� �ش� ��δ� ���� o, ���ԵǴ� ������ �ƴ϶�� �ش� ��δ� ���� x 
  *---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

for (int i = 0; i < N; i++)
	if (Indegree[i] == 0)
		q.push(i);

while (q.empty() != 1)
{
	int v = q.front();
	q.pop();

	for (int i = 0; i < G[v].size(); i++)
	{
		Indegree[G[v][i]]--;

		if (Indegree[G[v][i]] == 0)
			q.push(Indegree[G[v][i]]);
	}
}