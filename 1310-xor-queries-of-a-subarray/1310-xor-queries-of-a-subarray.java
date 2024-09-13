class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = queries.length;
        int m = arr.length;
        int[] nums = new int[n];
        int[] pre = new int[m];
        pre[0] = arr[0];
        for(int i=1; i<m; i++) {
            pre[i] = pre[i-1] ^ arr[i];
        }

        for(int i=0; i<n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0) nums[i] = pre[r];
            else nums[i] = pre[r] ^ pre[l-1];
        }
        return nums;
    }
}