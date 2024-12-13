class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        maxm, minm = 1, 1
        res = max(nums)
        for el in nums:
            if el == 0:
                maxm, minm = 1, 1
                continue
            tmp = maxm
            maxm = max(maxm * el, minm * el, el)
            minm = min(tmp * el, minm * el, el)
            res = max(res, maxm)
        return res