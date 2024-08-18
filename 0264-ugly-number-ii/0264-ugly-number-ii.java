class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        int f = 0, s = 0, t = 0;
        dp[0] = 1;
        
        for (int i = 1; i < n; i++) {
            int nextUgly = Math.min(dp[f] * 2, Math.min(dp[s] * 3, dp[t] * 5));
            dp[i] = nextUgly;
            
            if (nextUgly == dp[f] * 2) f++;
            if (nextUgly == dp[s] * 3) s++;
            if (nextUgly == dp[t] * 5) t++;
        }
        
        return dp[n - 1];
    }
}
