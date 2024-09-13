class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = queries.length;
        int[] nums = new int[n];

        for(int i=0; i<n; i++) {
            int res = 0;
            int l = queries[i][0];
            int r = queries[i][1];
            for(int j=l; j<=r; j++) {
                res ^= arr[j];
            }
            nums[i] = res;
        }
        return nums;
    }
}