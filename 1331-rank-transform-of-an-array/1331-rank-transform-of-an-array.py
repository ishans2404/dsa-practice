from heapq import heapify, heappush, heappop
class Solution:
    def arrayRankTransform(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        n = len(nums)
        idx = list(range(n))
        idx.sort(key=lambda x: nums[x])
        prev = int(-1e9 - 1)
        rank = 0
        for i in range(n):
            index = idx[i]
            if nums[index] != prev:
                rank += 1
            prev = nums[index]
            nums[index] = rank
        return nums