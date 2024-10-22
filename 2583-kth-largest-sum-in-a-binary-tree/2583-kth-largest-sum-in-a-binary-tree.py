# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        q = deque([root])
        level_sums = []
        while q:
            lvlSum = 0
            for _ in range(len(q)):
                node = q.popleft()
                lvlSum += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            level_sums.append(lvlSum)
        minHeap = []
        for sum_val in level_sums:
            heapq.heappush(minHeap, sum_val)
            if len(minHeap) > k:
                heapq.heappop(minHeap)

        return minHeap[0] if len(minHeap) == k else -1