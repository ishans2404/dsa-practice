class Solution:
    def maxScore(self, s: str) -> int:
        ones_count = s.count('1')
        max_score = 0
        current_score = 0

        for i in range(len(s) - 1):
            if s[i] == '0':
                current_score += 1
            else:
                ones_count -= 1

            max_score = max(max_score, current_score + ones_count)

        return max_score