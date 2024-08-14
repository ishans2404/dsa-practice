class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)

        def helper(dist):
            # count number of pairs with diff <= m
            l = 0
            res = 0
            for r in range(n):
                while nums[r] - nums[l] > dist:
                    l += 1
                res += r - l
            return res

        # binary search
        l, r = 0, nums[-1]
        while l < r:
            m = l + ((r - l) // 2)
            pairs = helper(m)
            if pairs >= k:
                r = m
            else:
                l = m + 1
        return r