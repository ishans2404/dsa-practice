from heapq import heapify, heappush, heappop
class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if not arr:
            return []
        res = arr.copy()
        n = len(res)
        heapify(arr)
        dic = {}
        cnt = 1
        for i in range(n):
            elem = heappop(arr)
            if elem in dic:
                continue
            dic[elem] = cnt
            cnt += 1
        for i in range(n):
            res[i] = dic[res[i]]
        return res