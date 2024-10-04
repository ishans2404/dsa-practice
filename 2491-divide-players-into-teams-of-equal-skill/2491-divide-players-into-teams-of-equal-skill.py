class Solution:
    def dividePlayers(self, nums: List[int]) -> int:
        nums.sort()
        flag = False
        s = nums[0] + nums[-1]
        for i in range(len(nums) // 2):
            if nums[i] + nums[-i-1] != s:
                return -1
        s = 0
        for i in range(len(nums) // 2):
            s += nums[i] * nums[-i-1]
        return s