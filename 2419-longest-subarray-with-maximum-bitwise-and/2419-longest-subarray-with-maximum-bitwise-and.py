class Solution:
    def longestSubarray(self, s: List[int]) -> int:
        if len(s) == 1:
            return 1
        maxLen = 1
        maxElem = max(s)
        tempLen = 0
        for i in s:
            if i == maxElem:
                tempLen += 1
            else:
                maxLen = max(maxLen, tempLen)
                tempLen = 0
        maxLen = max(maxLen, tempLen)
        return maxLen