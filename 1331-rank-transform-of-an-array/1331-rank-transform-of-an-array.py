from heapq import heapify, heappush, heappop
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr:
            return []
        res = arr.copy()
        n = len(res)
        for i in range(n):
            arr[i] = (arr[i], i)
        heapify(arr)
        prev = int(-1e9-1)
        rank = 0
        for i in range(n):
            elem, idx = heappop(arr)
            if elem != prev:
                rank += 1
            prev = elem
            res[idx] = rank
        return res