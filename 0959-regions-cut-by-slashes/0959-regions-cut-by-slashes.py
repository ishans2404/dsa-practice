class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        R, C = len(grid), len(grid[0])

        # initialize new grid
        mygrid = [[False] * (C * 3) for i in range(R * 3)]
        row, col = R*3, C*3

        # fill new grid
        for x in range(R):
            for y in range(C):
                i, j = x*3, y*3
                if grid[x][y] == "/":
                    mygrid[i][j+2] = True
                    mygrid[i+1][j+1] = True
                    mygrid[i+2][j] = True
                elif grid[x][y] == "\\":
                    mygrid[i][j] = True
                    mygrid[i+1][j+1] = True
                    mygrid[i+2][j+2] = True
        
        # directions = down, up, right, left
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        # mark the visited cells true   
        def bfs(i, j):
            q = collections.deque()
            q.append((i, j))
            mygrid[i][j] = True

            while q:
                x, y = q.popleft()
                for dx, dy in directions:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < row and 0 <= ny < col and not mygrid[nx][ny]:
                        mygrid[nx][ny] = True
                        q.append((nx, ny))

        region = 0
        for i in range(row):
            for j in range(col):
                if not mygrid[i][j]:
                    region += 1
                    bfs(i, j)

        return region