class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        # bfs
        m, n = len(isWater), len(isWater[0])
        matrix = [[-1] * n for _ in range(m)]
        que = deque()
        for r in range(m):
            for c in range(n):
                if isWater[r][c] == 1:
                    que.append((r, c, 0))
                    matrix[r][c] = 0
        dirkn = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while que:
            r, c, height = que.popleft()
            for dr, dc in dirkn:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and matrix[nr][nc] == -1:
                    matrix[nr][nc] = height + 1
                    que.append((nr, nc, height + 1))
        return matrix