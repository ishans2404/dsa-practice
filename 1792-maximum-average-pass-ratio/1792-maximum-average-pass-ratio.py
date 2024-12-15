from heapq import heapify, heappush, heappop
class Solution:
    def maxAverageRatio(self, c: List[List[int]], e: int) -> float:
        res = 0
        n = len(c)
        for i in range(n):
            p, t = c[i][0], c[i][1]
            c[i] = (p/t - (p+1)/(t+1), p, t)
        heapify(c)
        for _ in range(e):
            r, p, t = heappop(c)
            p, t = p + 1, t + 1
            diff = p/t - (p+1)/(t+1)
            heappush(c, (diff, p, t))
        for r, p, t in c:
            res += p/t
        return res/n