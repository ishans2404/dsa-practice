class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        top, bot = sum(grid[0]) - grid[0][0], 0
        res = max(top, bot)
        for i in range(1, n):
            top -= grid[0][i]
            bot += grid[1][i - 1]
            res = min(res, max(top, bot))
        return res