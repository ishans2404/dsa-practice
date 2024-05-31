class Solution {
public:
    vector<int> countBits(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i] = (i%2 == 0) ? (dp[i/2]) : (1 + dp[i/2]);
        }
        return dp;
    }
};