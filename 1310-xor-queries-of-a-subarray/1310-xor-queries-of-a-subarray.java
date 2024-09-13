class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = queries.length;
        int m = arr.length;
        int[] nums = new int[n];
        for(int i=1; i<m; i++) {
            arr[i] ^= arr[i-1];
        }

        for(int i=0; i<n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0) nums[i] = arr[r];
            else nums[i] = arr[r] ^ arr[l-1];
        }
        return nums;
    }
}