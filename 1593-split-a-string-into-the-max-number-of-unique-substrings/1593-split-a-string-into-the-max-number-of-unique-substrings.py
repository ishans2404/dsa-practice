class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        curr_seen = set()
        def dfs(i):
            if i == len(s):
                return 0
            res = 0
            for j in range(i, len(s)):
                sub = s[i:j+1]
                if sub not in curr_seen:
                    curr_seen.add(sub)
                    res = max(res, 1 + dfs(j+1))
                    curr_seen.remove(sub)
            return res
        return dfs(0)