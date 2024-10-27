class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        R, C = len(matrix), len(matrix[0])
        dp = {}

        def dfs(r, c):
            if r == R or c == C or matrix[r][c] == 0:
                return 0
            if (r, c) in dp:
                return dp[(r, c)]
            dp[(r, c)] = 1 + min(dfs(r+1, c), dfs(r, c+1), dfs(r+1, c+1))
            return dp[(r, c)]

        res = 0
        for r in range(R):
            for c in range(C):
                res += dfs(r, c)
                
        return res