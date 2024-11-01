class Solution:
    def makeFancyString(self, s: str) -> str:
        chars = []
        chars.append([s[0], 1])
        for i in range(1, len(s)):
            if s[i] == chars[-1][0]:
                if chars[-1][1] == 2:
                    continue
                chars[-1][1] += 1
            else:
                chars.append([s[i], 1])
        return ''.join(char * count for char, count in chars)
