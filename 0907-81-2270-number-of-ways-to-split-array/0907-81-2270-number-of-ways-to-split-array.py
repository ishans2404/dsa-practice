class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        pre = [0] * (n + 1)
        suf = pre.copy()
        for i in range(n):
            pre[i + 1] = pre[i] + nums[i]
            suf[n - i - 1] = suf[n - i] + nums[n - i - 1]
        res = 0
        for i in range(n - 1):
            if pre[i + 1] >= suf[i + 1]:
                res += 1
        return res