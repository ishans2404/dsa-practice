# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        levelSum = []
        q = deque([root])

        while q:
            lvlSum = 0
            for i in range(len(q)):
                node = q.popleft()
                lvlSum += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            levelSum.append(lvlSum)
        
        q = deque([root])
        root.val = 0
        level = 0
        while q:
            for i in range(len(q)):
                node = q.popleft()
                childSum = 0
                if node.left:
                    childSum += node.left.val
                if node.right:
                    childSum += node.right.val
                if node.left:
                    node.left.val = levelSum[level + 1] - childSum
                    q.append(node.left)
                if node.right:
                    node.right.val = levelSum[level + 1] - childSum
                    q.append(node.right)
            level += 1
        
        return root