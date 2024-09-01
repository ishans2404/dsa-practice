class Solution {
    public int[][] construct2DArray(int[] og, int m, int n) {
        if(m*n != og.length) return new int[0][0];
        int[][] arr = new int[m][];

        for(int i=0; i<m; i++){
           arr[i] = Arrays.copyOfRange(og, i*n, i*n+n);
        }
        return arr;
    }
}