class Solution {
public:
    int function(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = nums.size(), sum = 0, c = 0;
        while(r < n) {
            sum += nums[r];
            while(l <= r && sum > goal) {
                sum -= nums[l++];
            }
            c += r++ - l;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return function(nums, goal) - function(nums, goal-1);
    }
};