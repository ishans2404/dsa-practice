class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        m = len(part)
        while True:
            k = s.find(part)
            if k == -1:
                return s
            else:
                s = s[:k] + s[k+m:]
        return s