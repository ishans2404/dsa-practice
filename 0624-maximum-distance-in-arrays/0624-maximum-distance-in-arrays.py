class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        cur_min, cur_max = arrays[0][0], arrays[0][-1]
        diff = 0
        n = len(arrays)

        for i in range(1, n):
            arr = arrays[i]
            diff = max(diff, arr[-1] - cur_min, cur_max - arr[0])
            cur_min = min(cur_min, arr[0])
            cur_max = max(cur_max, arr[-1])

        return diff