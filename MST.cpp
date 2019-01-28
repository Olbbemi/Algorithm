/*
	Spanning Tree : �׷������� ����Ŭ�� ������ Ʈ�� [ ������ ���� ���� x ]

		MST : Spanning Tree �� ����� ������ ���� �ּҰ� �ǵ��� ������ �����ϴ� �˰��� [ Minimum Spanning Tree ]

		- Prim : ������ �������� ������ ����� ���� �� ����ġ�� ���� ���� ���� ���� -> O(VE) 
	
		- Prim �˰��� �ּ� ���� �̿��� �ð����⵵ : O(ElogE)

		- Kruskal : ������ �������� ����ġ�� ���� ���� �������� ����, ����Ŭ�� �����ϸ� �ȵǹǷ� ������ ������ �� �� ������ �̹� ������ �����̸� ���� x [ Union - Find �̿� ]  -> O(ElogE)
*/
	
// Prim Algorithm
v[a].push_back(make_pair(b, G));
v[b].push_back(make_pair(a, G));

Check[1] = 1;
for (int i = 0; i < v[1].size(); i++)
	q.push(make_pair(v[1][i].first, v[1][i].second));

while (q.empty() != 1)
{
	Min = INF;
	while (q.empty() != 1)
	{
		Ftemp = q.front().first, Stemp = q.front().second;
		q.pop();

		if (Check[Ftemp] == 0)
		{
			temp.push(make_pair(Ftemp, Stemp));

			if (Min > Stemp)
			{
				Min = Stemp;
				index = Ftemp;
			}
		}
	}

	result += Min;
	Check[index] = 1;

	while (temp.empty() != 1)
	{
		int a = temp.front().first, b = temp.front().second;
		temp.pop();

		if (Check[a] == 0)
			q.push(make_pair(a, b));
	}

	for (int i = 0; i < v[index].size(); i++)
	{
		if (Check[v[index][i].first] == 0)
			q.push(make_pair(v[index][i].first, v[index][i].second));
	}
}

// Prim Algorithm + Heap
v[a].push_back(make_pair(b, G));
v[b].push_back(make_pair(a, G));

Check[1] = 1;
for (int i = 0; i < v[1].size(); i++)
	q.push(make_pair(v[1][i].second, v[1][i].first));

while (q.empty() != 1)
{
	int Ftemp = q.top().first, Stemp = q.top().second;
	q.pop();
	if (Check[Stemp] == 0)
	{
		result += Ftemp;
		Check[Stemp] = 1;

		for (int i = 0; i < v[Stemp].size(); i++)
			if (Check[v[Stemp][i].first] == 0)
				q.push(make_pair(v[Stemp][i].second, v[Stemp][i].first));
	}
}

// Kruskal Algorithm
for (int i = 1; i <= N; i++)
	Parent[i] = i;

v.push_back(INFO(a, G, b));
sort(v.begin(), v.end(), cmp);

for (int i = 0; i < v.size(); i++)
{
	int X = Find(v[i].start);
	int Y = Find(v[i].end);

	if (X != Y)
	{
		result += v[i].weight;

		if (Rank[X] > Rank[Y])
		{
			Parent[Y] = X;
			Rank[X] += Rank[Y];
		}
		else
		{
			Parent[X] = Y;
			Rank[Y] += Rank[X];
		}
	}
}

int Find(int x)
{
	if (x == Parent[x])
		return x;
	else
		return Parent[x] = Find(Parent[x]);
}

bool cmp(const INFO &u, const INFO &v)
{
	return u.weight < v.weight;
}