import math
from heapq import heapify, heappush, heappop
class Solution:
    def pickGifts(self, g: List[int], k: int) -> int:
        for i in range(len(g)):
            g[i] = 0 - g[i]
        heapify(g)
        for i in range(k):
            el = heappop(g)
            el = 0 - int(math.sqrt(abs(el)))
            heappush(g, el)
        return 0 - sum(g)
