class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int sum, add = 0, n = nums.size();
        for(int i=0; i<k; i++) add += nums[i];
        sum = add;
        for(int i=k; i<n; i++) {
            add += nums[i] - nums[i-k];
            sum = max(sum, add);
        }
        return double(sum)/k;        
    }
};