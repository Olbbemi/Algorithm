# DDA Algorithm

**DDA** : 타일 기반에서 기울기를 이용하여 출발지점부터 도착지점까지 직선을 그리는 알고리즘

- 실수기반의 연산이므로 오버헤드와 오차가 심함



- 기울기 >= 1 (*dalta_x < delta_y*)

  ```
  float slope = delta_y / delta_x;

  for(int i = 0; i < delta_y; i++)
  {
  	//rendering
  	x = Round(x + 1 / slope);

  }
  ```





- 기울기 < 1 (*delta_y < delta_x*)

  ```
  float slope = delta_y / delta_x;

  for(int j = 0; j < delta_x; j++)
  {
  	//rendering
  	y = Round(y + slope);
  }
  ```




- Source

```
int xpos, ypos;
pair<int, int> start_info, end_info;

if (p_SxPos < p_ExPos)
{
	start_info.first = p_SxPos;	start_info.second = p_SyPos;
	end_info.first = p_ExPos;	end_info.second = p_EyPos;
}
else
{
	start_info.first = p_ExPos;	start_info.second = p_EyPos;
	end_info.first = p_SxPos;	end_info.second = p_SyPos;
}

float delta_x = (float)abs(end_info.first - start_info.first)
				, delta_y = (float)abs(end_info.second - start_info.second);

float slope =  delta_y / delta_x;

if (slope >= 1)
{
	if (start_info.second < end_info.second)
	{
		xpos = start_info.first;
		for (int i = start_info.second; i <= start_info.second + (int)delta_y; i++)
		{
			//(i,xpos) rendering
			xpos = Round((float)xpos + 1 / slope);
		}
	}
	else
	{
		xpos = start_info.first;
		for (int i = start_info.second; i >= start_info.second - delta_y; i--)
		{
			//(i,xpos) rendering
			xpos = Round((float)xpos + 1 / slope);
		}
	}
}
else
{
	if (start_info.second < end_info.second)
	{
		ypos = start_info.second;
		for (int j = start_info.first; j <= start_info.first + (int)delta_x; j++)
		{
			//(ypos, j) rendering
			ypos = Round(((float)ypos + slope));
		}
	}
	else
	{
		ypos = start_info.second;
		for (int j = start_info.first; j <= start_info.first + (int)delta_x; j++)
		{
			//(ypos, j) rendering
			ypos = Round(((float)ypos - slope));
		}
	}
}
```

