class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> v;
        const int mod = 1e9 + 7;
        for(int i=0; i<n; i++) {
            int pre = 0;
            for(int j=i; j<n; j++) {
                pre += nums[j];
                v.push_back(pre);
            }
        }
        sort(v.begin(), v.end());
        long long res = 0;
        for(int i=l-1; i<=r-1; i++) res += v[i];
        res %= mod;

        return res;
    }
};