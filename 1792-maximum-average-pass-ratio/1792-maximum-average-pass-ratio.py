from heapq import heapify, heappush, heappop
class Solution:
    def maxAverageRatio(self, c: List[List[int]], e: int) -> float:
        res = 0
        nums = []
        for p, t in c:
            diff = (p/t) - ((p+1)/(t+1))
            nums.append([diff, p, t])
        heapify(nums)
        while e > 0:
            e -= 1
            r, p, t = heappop(nums)
            p += 1
            t += 1
            diff = (p/t) - ((p+1)/(t+1))
            heappush(nums, [diff, p, t])
        while nums:
            r, p, t = heappop(nums)
            res += p/t
        
        return res/len(c)


