class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        def computeXor(nums: List[int]) -> int:
            res = 0
            for num in nums:
                res ^= num
            return res

        n, m = len(nums1), len(nums2)
        if n & 1 and m & 1:
            return computeXor(nums1) ^ computeXor(nums2)
        if (n & 1) == 0 and (m & 1) == 0:
            return 0
        if n & 1:
            return computeXor(nums2)
        return computeXor(nums1)
