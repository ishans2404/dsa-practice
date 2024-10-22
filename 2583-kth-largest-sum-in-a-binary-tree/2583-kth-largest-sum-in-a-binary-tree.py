# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        q = deque([root])
        minHeap = []   # keep size atmost k
        while q:
            lvlSum = 0
            for i in range(len(q)):
                node = q.popleft()
                lvlSum += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            heapq.heappush(minHeap, lvlSum)
            if len(minHeap) > k:
                heapq.heappop(minHeap)
        return minHeap[0] if len(minHeap) == k else -1