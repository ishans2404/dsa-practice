class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total_sum = sum(nums)
        
        if abs(target) > total_sum:
            return 0
        
        dp = [0] * (2 * total_sum + 1)
        dp[total_sum] = 1
        
        for num in nums:
            next_dp = [0] * (2 * total_sum + 1)
            for s in range(-total_sum, total_sum + 1):
                if dp[s + total_sum] > 0:
                    next_dp[s + num + total_sum] += dp[s + total_sum]
                    next_dp[s - num + total_sum] += dp[s + total_sum]
            dp = next_dp
        
        return dp[target + total_sum]