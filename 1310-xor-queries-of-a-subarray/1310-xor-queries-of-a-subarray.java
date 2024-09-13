class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = queries.length;
        int[] nums = new int[n];
        int m = arr.length;
        int temp = 0;
        for(int i=0; i<m; i++) temp ^= arr[i];

        for(int i=0; i<n; i++) {
            int res = 0;
            int l = queries[i][0];
            int r = queries[i][1];
            if(r-l+1 <= m) {
                for(int j=l; j<=r; j++) {
                    res ^= arr[j];
                }
            }
            else {
                res = temp;
                for(int j=0; j<=l; j++) {
                    res ^= arr[j];
                }
                for(int j=r; j<m; j++) {
                    res ^= arr[j];
                }
            }
            nums[i] = res;
        }
        return nums;
    }
}