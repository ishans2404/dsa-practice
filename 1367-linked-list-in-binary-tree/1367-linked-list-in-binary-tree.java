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
    public boolean dfs(ListNode listhead, ListNode listcurr, TreeNode treenode) {
        if(listcurr == null) return true;
        if(treenode == null) return false;
        if(listcurr.val == treenode.val) listcurr = listcurr.next;
        else if(listhead.val == treenode.val) listhead = listhead.next;
        else listcurr = listhead;
        return dfs(listhead, listcurr, treenode.left) || dfs(listhead, listcurr, treenode.right);
    }

    public boolean isSubPath(ListNode head, TreeNode root) {
        return dfs(head, head, root);
    }
}