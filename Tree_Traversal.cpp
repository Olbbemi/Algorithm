/**-------------------------------------------------------------------------------------------------
  * ���� ��ȸ : ���� ��� �湮, ���� ���� Ʈ�� ���� ��ȸ, ���� ���� Ʈ�� ���� ��ȸ
  * ���� ��ȸ : ���� ���� Ʈ�� ���� ��ȸ, ���� ��� �湮, ���� ���� Ʈ�� ���� ��ȸ (�����Ͱ� ������������ ���)
  * ���� ��ȸ : ���� ���� Ʈ�� ���� ��ȸ, ���� ���� Ʈ�� ���� ��ȸ, ���� ��� �湮
  * ���� ��ȸ : ���� �������� ���������� ��ȸ (ť�� �̿�)
  *-------------------------------------------------------------------------------------------------*/

  // ���� ��ȸ
void PreOrder(NODE* root)
{
	if (root == nullptr)
		return;

	/*
	 * root->data ���
	 */
	PreOrder(root->Llink);
	PreOrder(root->Rlink);
}

// ���� ��ȸ
void InOrder(NODE* root)
{
	if (root == nullptr)
		return;

	InOrder(root->Llink);
	/*
	 * root->data ���
	 */
	InOrder(root->Rlink);
}


// ���� ��ȸ
void PostOrder(NODE* root)
{
	if (root == nullptr)
		return;

	PostOrder(root->Llink);
	PostOrder(root->Rlink);
	/*
	 * root->data ���
	 */
}

// ���� ��ȸ
queue<NODE*> level_queue;

void LevelOrder(NODE* root)
{
	level_queue.push(root);

	while (level_queue.size() != 0)
	{
		sub_tree = level_queue.pop();

		/*
		 * sub_tree->data ���
		 */

		if (sub_tree->Llink != nullptr)
			level_queue.push(sub_tree->Llink);

		if (sub_tree->Rlink != nullptr)
			level_queue.push(sbu_tree->Rlink);
	}
}