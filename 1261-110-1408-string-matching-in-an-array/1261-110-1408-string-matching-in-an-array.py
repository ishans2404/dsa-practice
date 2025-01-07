class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        def isSubstr(s, t):
            n, m = len(s), len(t)
            for i in range(n - m + 1):
                if s[i : i + m] == t:
                    return True
            return False
        res = []
        k = len(words)
        valid = [False] * k
        for i in range(k):
            for j in range(k):
                if not valid[j] and len(words[i]) > len(words[j]) and isSubstr(words[i], words[j]):
                    res.append(words[j])
                    valid[j] = True
        return res