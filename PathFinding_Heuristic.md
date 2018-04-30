# PathFinding Heuristic

- **Heuristic** : time complexity || space complexity 를 포기하고 가장 정답에 근접하는 값을 찾아 

  ​		결과로 사용하는 알고리즘

  ​


- **Manhattan distance**

  ```
  function heuristic(node)
  {
      dx = abs(node.x - goal.x)
      dy = abs(node.y - goal.y)
      return cost * (dx + dy)
  }
  ```

  ​


- **Diagonal distance**

  ```
  function heuristic(node)
  {
      dx = abs(node.x - goal.x)
      dy = abs(node.y - goal.y)
      return Scost * (dx + dy) + (Dcost - 2 * Scost) * min(dx, dy)
  }

  - Scost : 직선에 대한 비용, Dcost : 대각선에 대한 비용

  [Chebyshev Distance : Scost = 1, Dcost = 1]
  [Octile : Scost = 1, Dcost = sqrt(2)]
  ```

  ​

- **Euclidean distance**

  ```
  function heuristic(node)
  {
      dx = abs(node.x - goal.x)
      dy = abs(node.y - goal.y)
      return cost * sqrt(dx * dx + dy * dy)
  }
  ```


