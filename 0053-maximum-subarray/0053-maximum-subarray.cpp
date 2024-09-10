class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            sum = (sum < 0) ? 0 : sum;
        }
        return maxi;
    }
};