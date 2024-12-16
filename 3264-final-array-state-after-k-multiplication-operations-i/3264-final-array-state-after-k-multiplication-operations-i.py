from heapq import heapify, heappush, heappop 
class Solution:
    def getFinalState(self, nums: List[int], k: int, m: int) -> List[int]:
        n = len(nums)
        nums = [(nums[i], i) for i in range(n)]
        heapify(nums)
        for _ in range(k):
            el, idx = heappop(nums)
            el *= m
            heappush(nums, (el, idx))
        res = [None] * n
        for el, i in nums:
            res[i] = el
        return res