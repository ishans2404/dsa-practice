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
        for(int i = 0; i < m; i++) {
            Arrays.fill(matrix[i], -1);
        }
        fillMatrixInSpiral(m, n, head);
    }
    private void fillMatrixInSpiral(int rows, int columns, ListNode head) {
        int topRow = 0, bottomRow = rows - 1, leftColumn = 0, rightColumn = columns - 1;
        while (head != null) {
        
            for (int col = leftColumn; col <= rightColumn && head != null; col++) {
                matrix[topRow][col] = head.val;
                head = head.next;
            }
            topRow++;

        
            for (int row = topRow; row <= bottomRow && head != null; row++) {
                matrix[row][rightColumn] = head.val;
                head = head.next;
            }
            rightColumn--;

 
            for (int col = rightColumn; col >= leftColumn && head != null; col--) {
                matrix[bottomRow][col] = head.val;
                head = head.next;
            }
            bottomRow--;

       
            for (int row = bottomRow; row >= topRow && head != null; row--) {
                matrix[row][leftColumn] = head.val;
                head = head.next;
            }
            leftColumn++;
        }
    }
}

class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        Spiral spiral = new Spiral(m, n, head);
        return spiral.matrix;
    }
}