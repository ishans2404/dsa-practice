class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        def valid(arr):
            for i in range(k - 1):
                if arr[i] + 1 != arr[i + 1]:
                    return False
            return True
        
        n = len(nums)
        res = []
        for i in range(n-k+1):
            arr = nums[i:i+k]
            if valid(arr):
                res.append(arr[-1])
            else: res.append(-1)
        return res