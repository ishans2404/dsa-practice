# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, t: str) -> Optional[TreeNode]:
        stk = []
        i = 0
        while i < len(t):
            lvl = 0
            s = []
            while i < len(t) and t[i] == "-":
                lvl += 1
                i += 1
            while i < len(t) and 48 <= ord(t[i]) <= 57:
                s.append(t[i])
                i += 1
            s = int(''.join(s))
            if not stk:
                stk.append((TreeNode(s), lvl))
            else:
                while stk[-1][1] >= lvl:
                    stk.pop()
                node = stk[-1][0]
                if node.left:
                    node.right = TreeNode(s)
                    stk.append((node.right, lvl))
                else:
                    node.left = TreeNode(s)
                    stk.append((node.left, lvl))
        return stk[0][0]
