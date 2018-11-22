/**-------------------------------------------------------------------------------------------------
  * 전위 순회 : 현재 노드 방문, 좌측 서브 트리 전위 순회, 우측 서브 트리 전위 순회
  * 중위 순회 : 좌측 서브 트리 중위 순회, 현재 노드 방문, 우측 서브 트리 중위 순회 (데이터가 오름차순으로 출력)
  * 후위 순회 : 좌측 서브 트리 후위 순회, 우측 서브 트리 후위 순회, 현재 노드 방문
  * 레벨 순회 : 낮은 레벨부터 순차적으로 순회 (큐를 이용)
  *-------------------------------------------------------------------------------------------------*/

  // 전위 순회
void PreOrder(NODE* root)
{
	if (root == nullptr)
		return;

	/*
	 * root->data 출력
	 */
	PreOrder(root->Llink);
	PreOrder(root->Rlink);
}

// 중위 순회
void InOrder(NODE* root)
{
	if (root == nullptr)
		return;

	InOrder(root->Llink);
	/*
	 * root->data 출력
	 */
	InOrder(root->Rlink);
}


// 후위 순회
void PostOrder(NODE* root)
{
	if (root == nullptr)
		return;

	PostOrder(root->Llink);
	PostOrder(root->Rlink);
	/*
	 * root->data 출력
	 */
}

// 레벨 순회
queue<NODE*> level_queue;

void LevelOrder(NODE* root)
{
	level_queue.push(root);

	while (level_queue.size() != 0)
	{
		sub_tree = level_queue.pop();

		/*
		 * sub_tree->data 출력
		 */

		if (sub_tree->Llink != nullptr)
			level_queue.push(sub_tree->Llink);

		if (sub_tree->Rlink != nullptr)
			level_queue.push(sbu_tree->Rlink);
	}
}