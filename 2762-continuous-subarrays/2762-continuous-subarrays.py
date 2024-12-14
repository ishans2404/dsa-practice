class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        l = 0
        n = len(nums)
        maxm, minm = nums[0], nums[0]
        ws = 0
        res = 0
        for r in range(n):
            maxm = max(maxm, nums[r])
            minm = min(minm, nums[r])
            if maxm - minm > 2:
                ws = r - l
                res += (ws * (ws + 1)) // 2
                l = r
                maxm, minm = nums[r], nums[r]
                while abs(nums[r] - nums[l - 1]) <= 2:
                    l -= 1
                    maxm = max(maxm, nums[l])
                    minm = min(minm, nums[l])
                if l < r:
                    ws = r - l
                    res -= (ws * (ws + 1)) // 2
        ws = n - l
        res += (ws * (ws + 1)) // 2
        return res