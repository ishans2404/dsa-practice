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
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = -1;
            }
        }
        fillMatrixInSpiral(m, n, head);
    }
    private void fillMatrixInSpiral(int m, int n, ListNode curr) {
        int top = 0, bottom = m-1, left = 0, right= n-1;
        while(curr != null && top<=bottom && left <=right){
            // Fill top row (left to right)
            for(int i=left; i<=right && curr!=null; i++){
                matrix[top][i] = curr.val;
                curr = curr.next;
            }
            top++;

            // Fill right column (top to bottom)
            for(int i=top; i<=bottom && curr!=null; i++){
                matrix[i][right]= curr.val;
                curr = curr.next;
            }
            right--;

            // Fill bottom row (right to left)
            for(int i=right; i>=left && curr != null; i--){
                matrix[bottom][i] = curr.val;
                curr = curr.next;
            }
            bottom--;

            // Fill left column (bottom to top)
            for(int i=bottom; i>=top && curr!=null; i--){
                matrix[i][left] = curr.val;
                curr = curr.next;
            }
            left++;
        }
    }
}

class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        Spiral spiral = new Spiral(m, n, head);
        return spiral.matrix;
    }
}