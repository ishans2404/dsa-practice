class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapify(nums)
        ops = 0
        while nums[0] < k:
            ops += 1
            x = heappop(nums)
            y = heappop(nums)
            elem = x * 2 + y
            heappush(nums, elem)
        return ops