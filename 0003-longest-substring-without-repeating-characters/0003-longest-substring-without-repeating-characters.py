class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i, n = 0, len(s)
        seen = set()
        length = 0
        for j in range(n):
            while s[j] in seen:
                seen.remove(s[i])
                i += 1
            seen.add(s[j])
            length = max(length, j-i+1)
        return length