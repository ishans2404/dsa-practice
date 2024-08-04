class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> v;
        long long s;
        const int mod = 1e9 + 7;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                s = 0;
                for(int k=i; k<=j; k++) {
                    s += nums[k];
                }
                v.push_back(s);
            }
        }
        sort(v.begin(), v.end());
        s = 0;
        for(int i=l-1; i<=r-1; i++) s += v[i];
        s %= mod;

        return s;
    }
};