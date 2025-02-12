class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        def get_sum(n):
            summ = 0
            while n > 0:
                summ += n % 10
                n //= 10
            return summ
        digit_sum = defaultdict(list)
        for n in nums:
            heappush(digit_sum[get_sum(n)], -n)
        res = -1
        for k, v in digit_sum.items():
            if len(v) >= 2:
                tmp = 0
                tmp -= heappop(v)
                tmp -= heappop(v)
                res = max(res, tmp)
        return res