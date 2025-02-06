class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        product_count = defaultdict(int)
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                product = nums[i] * nums[j]
                product_count[product] += 1
        res = 0
        for count in product_count.values():
            res += count * (count - 1) // 2
        return 8 * res