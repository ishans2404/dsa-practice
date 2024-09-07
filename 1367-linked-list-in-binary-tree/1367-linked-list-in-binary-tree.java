/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean helper(ListNode listnode, TreeNode treenode) {
        if(listnode == null) return true;
        if(treenode == null || listnode.val != treenode.val) return false;
        boolean res = helper(listnode.next, treenode.left) || helper(listnode.next, treenode.right);
        return res;
    }

    public boolean isSubPath(ListNode head, TreeNode root) {
        if(helper(head, root)) return true;
        if(root == null) return false;
        return isSubPath(head, root.left) || isSubPath(head, root.right);
    }
}