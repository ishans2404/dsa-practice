class Solution:
    def minChanges(self, s: str) -> int:
        return sum((int(s[i]) ^ int(s[i+1])) for i in range(0, len(s)-1, 2))
