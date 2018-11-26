/**---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  *	Union - Find : ��ȣ ��Ÿ�� ���� 

  * Union : �� ������ ������ �ϳ��� ��ġ�� �Լ� 
  * Find : Ư�� ���Ұ� ���Ե� ������ ã�� �Լ�
		   
  * �ʱ� �� ������ ������ �� ������ �������� ����  [�� �迭�� �ε����� �ش� ���Ҹ� �ǹ��ϸ� �迭�� �����Ͱ� ������ �ǹ�] 	   
		=> �Ϲ����� ����� �̿��ϸ� pow(N,2) �ð����⵵�� �߻��ϹǷ� �̸� ��ξ��� �� ���߹�Ģ�� �̿� [Ʈ������ ���] �Ͽ� �ð����⵵�� logN ���Ϸ� ����		
		
  * ��� ���� : �� ���ҵ��� ������ ���տ� �������� Ʈ�������� �����Ǿ��ִ� ��� [1 �̶�� ���տ� 4 �� 5 �� ���������� Ʈ�������� 5 �� 4�� ���� ����� �� 4�� ã�� ���ؼ��� 2�� Ž���ؾ� ��] �̸� ��ٷ� ���տ� ���ϰ��ϴ� ��� 	
  * ���� ��Ģ : �� ������ �ϳ��� ��ĥ �� Ʈ���� ���̰� �� ���� ������ �θ� , �� ���� ������ �ڽ��� �Ǿ� Ž���ð��� ���̴� ��� [�ʱ� ����ġ�� ��� 1] 
  *---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void General_Union(int x , int y)
{
	int X , Y;
	X = General_Find(x);
	Y = General_Find(y);
	
	if(X == Y)
		return;
	else
		Set[X] = Y; // Set[Y] = X;
}

int General_Find(int x)
{
	if(x == Set[x])
		return x;
	else
		return General_Find(Set[x]);
}

void Upgrade_Union(int x , int y)
{
	int X , Y;
	
	X = Upgrade_Find(x);
	Y = Upgrade_Find(y);
	
	if(X == Y)
		return;
	else
	{
		if(rank[X] < rank[Y])
		{
			Set[X] = Y;
			rank[Y] += rank[X];
		}
		else
		{
			Set[Y] = X;
			rank[X] += rank[Y];		
		}
	}
}

int Upgrade_Find(int x)
{
	if(x == Set[x])
		return x;
	else
	{
		int temp = Find(Set[x]);
		Set[x] = temp;
		return temp;
	}
}