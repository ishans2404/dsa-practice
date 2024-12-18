class Solution:
    def finalPrices(self, p: List[int]) -> List[int]:
        n = len(p)
        res = p.copy()
        stk = []
        for i in range(n):
            while stk and p[stk[-1]] >= p[i]:
                j = stk.pop()
                res[j] -= p[i]
            stk.append(i)

        return res