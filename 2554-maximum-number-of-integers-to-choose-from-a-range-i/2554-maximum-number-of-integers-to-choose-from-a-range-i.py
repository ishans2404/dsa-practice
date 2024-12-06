class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        seen = set()
        for i in banned:
            if i <= n:
                seen.add(i)
        res = 0
        cnt = 0
        for i in range(1, n+1):
            if i in seen:
                continue
            if res + i <= maxSum:
                cnt += 1
                res += i
            else:
                return cnt
        return cnt