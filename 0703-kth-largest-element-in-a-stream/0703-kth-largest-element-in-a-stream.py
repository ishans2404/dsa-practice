class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.arr = sorted(nums)
        self.idx = -k

    def add(self, val: int) -> int:
        low, high = 0, len(self.arr)
        while low < high:
            mid = low + (high - low) // 2
            if self.arr[mid] < val:
                low = mid + 1
            else:
                high = mid
        
        self.arr.insert(low, val)
        return self.arr[self.idx]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)