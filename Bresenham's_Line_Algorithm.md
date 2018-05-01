# Bresenham's Line Algorithm

**Bresenham's Line** : 타일기반에서 정수의 사칙연산을 이용하여

​			출발지점부터 도착지점까지 직선을 그리는 알고리즘



- 기울기 >= 1 (dalta_x < delta_y)

  ```
  error = 0;
  for(int i = 0; i < delta_y; i++)
  {
  	if(error >= delta_y)
  	{
  		x++;
  		error -= delta_y;
  	}
  	
  	//rendering
  	error += delta_x;
  }
  ```



- 기울기 < 1 (delta_y < delta_x)

  ```
  error = 0;
  for(int j = 0; j < delta_x; j++)
  {
  	if(error >= delta_x)
  	{
  		y++;
  		error -= delta_x;
  	}
  	
  	//rendering
  	error += delta_y;
  }
  ```



```
int error, xpos, ypos;
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

int delta_x = abs(end_info.first - start_info.first)
				, delta_y = abs(end_info.second - start_info.second);

if (delta_x < delta_y)
{
	error = delta_y / 2;
	if (start_info.second < end_info.second)
	{
		xpos = start_info.first;
		for (int i = start_info.second; i <= start_info.second + delta_y; i++)
		{
			if (error >= delta_y)
			{
				xpos++;
				error -= delta_y;
			}
			
			//(i,xpos) rendering
			error += delta_x;
		}
	}
	else
	{
		xpos = start_info.first;
		for (int i = start_info.second; i >= start_info.second - delta_y; i--)
		{
			if (error >= delta_y)
			{
				xpos++;
				error -= delta_y;
			}
		
        	//(i, xpos) rendering
			error += delta_x;
		}
	}
}
else
{
	error = delta_x / 2;
	if (start_info.second < end_info.second)
	{
		ypos = start_info.second;
		for (int j = start_info.first; j <= start_info.first + delta_x; j++)
		{
			if (error >= delta_x)
			{
				ypos++;
				error -= delta_x;
			}

			//(ypos, j) rendering
			error += delta_y;
		}
	}
	else
	{
		ypos = start_info.second;
		for (int j = start_info.first; j <= start_info.first + delta_x; j++)
		{
			if (error >= delta_x)
			{
				ypos--;
				error -= delta_x;
			}
			
			//(ypos, j) rendering
			error += delta_y;
		}
	}
}
```



