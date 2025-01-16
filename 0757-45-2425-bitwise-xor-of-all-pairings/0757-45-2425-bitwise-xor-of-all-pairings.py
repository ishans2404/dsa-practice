class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        def computeXor(nums):
            res = 0
            for num in nums:
                res ^= num
            return res
        if m & 1 == 0:
            if n & 1 == 0:
                return 0
            return computeXor(nums2)
        else:
            if n & 1 == 0:
                return computeXor(nums1)
            else:
                return computeXor(nums1) ^ computeXor(nums2)