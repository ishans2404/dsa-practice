class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        if len(nums) <= k:
            self.minHeap = nums
        else:
            self.minHeap = nlargest(k, nums)
        heapify(self.minHeap)

    def add(self, val: int) -> int:
        if len(self.minHeap) < self.k:
            heappush(self.minHeap, val)
        elif val > self.minHeap[0]:
            heappop(self.minHeap)
            heappush(self.minHeap, val)
        return self.minHeap[0]
