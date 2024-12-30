class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 1000000007
        dp = {0: 1}

        res = 0
        for i in range(high + 1):
            if i not in dp:
                continue

            dp[i + zero] = (dp.get(i + zero, 0) + dp[i]) % MOD
            dp[i + one] = (dp.get(i + one, 0) + dp[i]) % MOD

            if low <= i <= high:
                res = (res + dp[i]) % MOD
        return res
