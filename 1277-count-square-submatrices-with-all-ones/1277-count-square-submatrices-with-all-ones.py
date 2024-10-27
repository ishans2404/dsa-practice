class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        R, C = len(matrix), len(matrix[0])
        dp = defaultdict(int)
        res = 0
        for r in range(R):
            curr = defaultdict(int)
            for c in range(C):
                if matrix[r][c] == 1:
                    curr[c] = 1 + min(
                        dp[c],
                        dp[c - 1],
                        curr[c - 1]
                    )
                    res += curr[c]
            dp = curr
                
        return res