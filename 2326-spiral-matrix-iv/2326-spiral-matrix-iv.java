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

class Spiral {
    int[][] matrix;
    public Spiral(int m, int n, ListNode head) {
        matrix = new int[m][n];
        fillMatrixInSpiral(m, n, head);
    }
    private void fillMatrixInSpiral(int m, int n, ListNode head) {
        int l = 0, r = n-1, t = 0, b = m-1;
        int cells = 0, tot = m*n;

        while(head != null || cells < tot) {
            for(int j=l; j<=r && l<=r && t<=b; j++) {
                if(head != null) {
                    matrix[t][j] = head.val;
                    head = head.next;
                }
                else matrix[t][j] = -1;
                cells++;
            }
            t++;
            for(int i=t; i<=b && l<=r && t<=b; i++) {
                if(head != null) {
                    matrix[i][r] = head.val;
                    head = head.next;
                }
                else matrix[i][r] = -1;
                cells++;
            }
            r--;
            for(int j=r; j>=l && l<=r && t<=b; j--) {
                if(head != null) {
                    matrix[b][j] = head.val;
                    head = head.next;
                }
                else matrix[b][j] = -1;
                cells++;
            }
            b--;
            for(int i=b; i>=t && l<=r && t<=b; i--) {
                if(head != null) {
                    matrix[i][l] = head.val;
                    head = head.next;
                }
                else matrix[i][l] = -1;
                cells++;
            }
            l++;
        }
    }
}

class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        Spiral spiral = new Spiral(m, n, head);
        return spiral.matrix;
    }
}