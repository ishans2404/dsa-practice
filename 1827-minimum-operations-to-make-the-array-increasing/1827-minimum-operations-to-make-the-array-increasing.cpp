class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int c = 0, t;
        for(int i=1; i<n; i++) {
            if(nums[i] <= nums[i-1]) {
                t = nums[i-1] - nums[i] + 1;
                nums[i] += t;
                c += t;
            }
        }
        return c;
    }
};