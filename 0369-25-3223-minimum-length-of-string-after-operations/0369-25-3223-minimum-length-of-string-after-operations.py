class Solution:
    def minimumLength(self, s: str) -> int:
        count = Counter(s)
        res = 0
        for k, v in count.items():
            res += 1
            if v & 1 == 0:
                res += 1
        return res