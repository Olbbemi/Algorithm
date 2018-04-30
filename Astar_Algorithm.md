# A* Algorithm

**A*** :  타일기반에서 출발지에서 목적지까지 이동하는 최단경로를 찾는 알고리즘 [ *휴리스틱 추정값을 기반* ]

- **F(n)  = G(n) + H(n)** 

​	[ G : *출발지부터 현재 위치까지 이동한 횟수*, H: *현재 위치에서 목적지까지의 휴리스틱 추정값* ]

- **Open List** : 현재 정점을 기준으로 인접한 정점 중 최단 경로 후보가 될 수 있는 정점의 집합

- **Close List** : Open List에 존재하는 정점 중 이미 방문한 정점의 집합

  ​	[ *Close List 에 저장된 모든 정점이 최단경로를 의미x* ]

- 최단 경로 후보로 등록될 정점이 이미 Open List 및 Close List에 존재한다면

  ​	G 값을 비교하여 갱신 및 부모정보를 변경

  ​		


```
// 시작 노드 생성
NODE *new_node = new NODE;
new_node->parent = nullptr;
new_node->row = startY;
new_node->col = startX;
new_node->G = 0.0;
new_node->H = ((float)abs(ExPos - SxPos) + (float)abs(EyPos - SyPos));
new_node->F = new_node->G + new_node->H;

Open_List.push_back(new_node);

// 최단 경로 후보로 등록될 정점이 Close List에 존재하는지 확인
for (auto list = Close_List.begin(); list != Close_List.end(); list++)
{
	if ((*list)->col == Xtemp && (*list)->row == Ytemp)
	{
		if ((i & 1) == 1 && (*list)->G > pivot->G + 1.5f)
		{
			(*list)->G = pivot->G + 1.5f;
			(*list)->F = (*list)->G + (*list)->H;
			(*list)->parent = pivot;
		}
		else if ((i & 1) == 0 && (*list)->G > pivot->G + 1.0f)
		{
			(*list)->G = pivot->G + 1.0f;
			(*list)->F = (*list)->G + (*list)->H;
			(*list)->parent = pivot;
		}

		break;
	}
}

// 최단 경로 후보로 등록될 정점이 Open List에 존재하는지 확인
for (auto list = Open_List.begin(); list != Open_List.end(); list++)
{
	if ((*list)->col == Xtemp && (*list)->row == Ytemp)
	{
		if ((i & 1) == 1 && (*list)->G > pivot->G + 1.5f)
		{
			(*list)->G = pivot->G + 1.5f;		
			(*list)->F = (*list)->G + (*list)->H;		
			(*list)->parent = pivot;
		}
		else if( (i & 1) == 0 && (*list)->G > pivot->G + 1.0f)
		{
			(*list)->G = pivot->G + 1.0f;			
			(*list)->F = (*list)->G + (*list)->H;			
			(*list)->parent = pivot;
		}
		
		break;
	}
}

// Open List || Close List 에 존재하지 않으면 새로운 정점 추가
NODE *new_node = new NODE;
new_node->col = Xtemp;
new_node->row = Ytemp;
new_node->parent = pivot;
	
if ((i & 1) == 1)
	new_node->G = pivot->G + 1.5f;
else
	new_node->G = pivot->G + 1.0f;

new_node->H = ((float)abs(Xtemp - endX) + (float)abs(Ytemp - endY));
new_node->F = new_node->G + new_node->H;
Open_List.push_back(new_node);

// F 값을 기준으로 오름차순 정렬
sort(Open_List.begin(), Open_List.end(), cmp); 
```



- **Tie Breaking** : Open List 에 등록되는 정점들의 F 값이 동일한 값을 가지는 

  ​	경우가 많으면 탐색해야할 정점 개수가 증가

-> H 값에 부가적인 연산을 추가함으로써 F 값이 동일한 경우를 줄이는 것

```
dx1 = current.x - goal.x;	dy1 = current.y - goal.y;
dx2 = start.x - goal.x;		dy2 = start.y - goal.y;
alpha = abs(dx1 * dy2 - dx2 * dy1)
H(n) += alpha * 0.001
```

