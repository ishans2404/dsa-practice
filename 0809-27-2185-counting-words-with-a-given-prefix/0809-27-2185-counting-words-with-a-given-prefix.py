class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        m = len(pref)
        res = 0
        for w in words:
            if len(w) >= m and w[:m] == pref:
                res += 1
        return res