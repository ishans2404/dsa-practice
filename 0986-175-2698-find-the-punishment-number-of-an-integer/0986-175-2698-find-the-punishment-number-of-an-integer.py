class Solution:
    def __init__(self):
        self.nums = []
        def partition(i, cur: int, tgt: int, s: str):
            if i == len(s) and cur == tgt:
                return True
            for j in range(i, len(s)):
                if partition(j + 1, cur + int(s[i : j+1]), tgt, s):
                    return True
            return False
        for i in range(1, 1001):
            if partition(0, 0, i, str(i * i)):
                self.nums.append(i)

    def punishmentNumber(self, n: int) -> int:
        res = 0
        for num in self.nums:
            if num <= n:
                res += num * num
        return res