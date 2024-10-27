class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        R, C = len(matrix), len(matrix[0])
        dp = [0] * (C+1)
        res = 0
        for r in range(R):
            curr = [0] * (C+1)
            for c in range(C):
                if matrix[r][c] == 1:
                    curr[c+1] = 1 + min(
                        dp[c+1],
                        dp[c],
                        curr[c]
                    )
                    res += curr[c+1]
            dp = curr
                
        return res