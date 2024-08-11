from typing import List

class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        from collections import deque
        
        def is_connected():
            visited = [[False] * n for _ in range(m)]
            
            def bfs(start_x, start_y):
                q = deque([(start_x, start_y)])
                visited[start_x][start_y] = True
                while q:
                    x, y = q.popleft()
                    for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                        nx, ny = x + dx, y + dy
                        if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] == 1:
                            visited[nx][ny] = True
                            q.append((nx, ny))
            
            # Find the first 1 cell to start BFS
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1:
                        bfs(i, j)
                        break
                else:
                    continue
                break
            
            # Check if there's any 1 cell that is not visited
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1 and not visited[i][j]:
                        return False
            return True
        
        def count_islands():
            visited = [[False] * n for _ in range(m)]
            count = 0
            
            def bfs(x, y):
                q = deque([(x, y)])
                visited[x][y] = True
                while q:
                    cx, cy = q.popleft()
                    for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0)):
                        nx, ny = cx + dx, cy + dy
                        if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] == 1:
                            visited[nx][ny] = True
                            q.append((nx, ny))
            
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1 and not visited[i][j]:
                        count += 1
                        bfs(i, j)
            return count
        
        m, n = len(grid), len(grid[0])
        
        # Check if the grid is already disconnected
        if count_islands() != 1:
            return 0
        
        # Try removing one cell and check connectivity
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    if count_islands() != 1:
                        return 1
                    grid[i][j] = 1
        
        # If none of the single removals work, it means two cells are needed
        return 2
