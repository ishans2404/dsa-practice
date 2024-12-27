class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        maxi = values[0]
        ans = 0
        n = len(values)
        for i in range(1, n):
            ans = max(ans, maxi + values[i] - i)
            maxi = max(maxi, values[i] + i)
        return ans