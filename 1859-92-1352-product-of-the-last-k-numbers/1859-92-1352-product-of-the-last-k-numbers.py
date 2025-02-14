class ProductOfNumbers:
    def __init__(self):
        self.nums = []

    def add(self, num: int) -> None:
        if num == 0:
            self.nums = []
            return
        if not self.nums:
            self.nums.append(num)
        else:
            self.nums.append(num * self.nums[-1])

    def getProduct(self, k: int) -> int:
        n = len(self.nums)
        if n < k:
            return 0
        elif n == k:
            return self.nums[-1]
        return self.nums[-1] // self.nums[n - k - 1] 

# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)