class Solution:
    # digit sums for numbers 0-99
    def __init__(self):
        self.sums = [
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
            2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
            4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
            6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
            8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18
        ]

    def get_sum(self, n: int) -> int:
        q = n // 10000
        r = n % 10000
        q0 = r // 100
        r0 = r % 100
        q1 = q // 100
        r1 = q % 100
        q2 = q1 // 100
        r2 = q1 % 100
        return self.sums[r0] + self.sums[q0] + self.sums[r1] + self.sums[r2] + self.sums[q2]

    def maximumSum(self, nums: List[int]) -> int:
        digit_sum = defaultdict(list)
        for n in nums:
            heappush(digit_sum[self.get_sum(n)], -n)
        res = -1
        for k, v in digit_sum.items():
            if len(v) >= 2:
                tmp = 0
                tmp -= heappop(v)
                tmp -= heappop(v)
                res = max(res, tmp)
        return res