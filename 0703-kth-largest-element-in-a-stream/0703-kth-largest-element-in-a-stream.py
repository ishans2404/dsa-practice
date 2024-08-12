class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.arr = sorted(nums)
        self.idx = -k

    def add(self, val: int) -> int:
        self.arr.append(val)
        self.arr = sorted(self.arr)
        return self.arr[self.idx]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)