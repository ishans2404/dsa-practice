# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:

        def minSwaps(arr: List, n: int) -> int:
            swp = 0
            arr_pos = []
            for i in range(n):
                arr_pos.append((arr[i], i))
            arr_pos.sort()
            vis = {k: False for k in range(n)}
            for i in range(n):
                if vis[i] or arr_pos[i][0] == i:
                    continue
                cycle_size = 0
                j = i
                while not vis[j]:
                    vis[j] = True
                    j = arr_pos[j][1]
                    cycle_size += 1
                if cycle_size > 0:
                    swp += (cycle_size - 1)
            return swp

        q = deque()
        q.append(root)
        res = 0
        while q:
            level_size = len(q)
            curr_level = []
            for _ in range(level_size):
                node = q.popleft()
                curr_level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            if level_size > 1:
                tmp = minSwaps(curr_level, level_size)
                res += tmp
        
        return res