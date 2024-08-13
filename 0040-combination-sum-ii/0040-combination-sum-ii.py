class Solution:
    def combinationSum2(self, c: List[int], t: int) -> List[List[int]]:
        c.sort()
        n = len(c)
        res = []

        def backtrack(start, curr, total):
            if total == t:
                res.append(curr.copy())
                return
            if total > t or start >= n:
                return
            for i in range(start, n):
                # Skip duplicates
                if i > start and c[i] == c[i - 1]:
                    continue
                # Include c[i] in the current combination
                curr.append(c[i])
                backtrack(i + 1, curr, total + c[i])
                # Backtrack, remove the last element
                curr.pop()
        
        backtrack(0, [], 0)
        return res
