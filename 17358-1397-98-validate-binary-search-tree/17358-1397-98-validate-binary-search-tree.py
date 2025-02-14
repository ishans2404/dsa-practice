# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def validate(node, lbound, rbound):
            if not node:
                return True
            if node.val >= rbound or node.val <= lbound:
                return False
            return validate(node.left, lbound, node.val) and validate(node.right, node.val, rbound)
        
        return validate(root, float('-inf'), float('inf'))