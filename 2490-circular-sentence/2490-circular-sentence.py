class Solution:
    def isCircularSentence(self, s: str) -> bool:
        if s[0] != s[-1]:
            return False
        for i in range(len(s)):
            if s[i] == ' ':
                if s[i-1] != s[i+1]:
                    return False
        return True