class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        check = []
        res = []
        check.append(1)
        diff = 1
        # Create the prefix array check for all consecutive numbers
        for i in range(1, len(nums)):
            if nums[i - 1] + 1 == nums[i]:  # consecutive
                diff += 1
            else:  # not consecutive
                diff = 1
            check.append(diff)

        # Find in the check vector if the difference is equal to k hence proving the sub array has consecutive number
        for i in range(len(nums) - k + 1):
            last_elem = check[i + k - 1]
            first_elem = check[i]
            if(last_elem - first_elem + 1) == k:
                res.append(nums[i + k - 1])
            else:
                res.append(-1)
        return res