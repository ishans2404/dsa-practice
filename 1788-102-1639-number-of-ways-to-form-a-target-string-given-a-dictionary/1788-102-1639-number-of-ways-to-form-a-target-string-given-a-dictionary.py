class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        m, n = len(target), len(words[0])
        MOD = 10 ** 9 + 7
        curr = [0] * 26
        counts = [[0 for _ in range(26)] for _ in range(n)]
        for i in range(n):
            for w in words:
                counts[i][ord(w[i]) - ord('a')] += 1
        
        dp = [0] * m + [1]
        for i in range(n-1, -1, -1):
            new_dp = [0] * m + [1]
            for j in range(m-1, -1, -1):
                k = ord(target[j]) - ord('a')
                if not counts[i][k]:
                    new_dp[j] = dp[j]
                else:
                    new_dp[j] = (dp[j] + counts[i][k] * dp[j+1]) % MOD
            dp = new_dp

        return new_dp[0]