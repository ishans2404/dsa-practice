class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        def helper(start, end):
            curr, prev = 0, 0
            for i in range(start, end + 1):
                curr, prev = max(curr, prev + nums[i]), curr
            return curr
        return max(nums[0], helper(1, n - 1), helper(0, n - 2))