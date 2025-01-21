class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        for i in range(1, n):
            grid[0][i] += grid[0][i - 1]
            grid[1][i] += grid[1][i - 1]
        res = float('inf')
        tmp = grid[0][-1] - grid[0][0]
        tmp = max(tmp, 0)
        res = min(res, tmp)
        for i in range(1, n):
            tmp = grid[0][-1] - grid[0][i]
            tmp = max(tmp, grid[1][i - 1])
            res = min(res, tmp)
        return res