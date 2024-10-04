class Solution:
    def dividePlayers(self, nums: List[int]) -> int:
        nums.sort()
        s = nums[0] + nums[-1]
        res = 0
        for i in range(len(nums) // 2):
            res += nums[i] * nums[-i-1]
            if nums[i] + nums[-i-1] != s:
                return -1
        return res