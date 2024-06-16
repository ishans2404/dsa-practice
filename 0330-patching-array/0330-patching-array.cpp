class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long missing = 1;
        int patch = 0;
        int idx = 0;
        int k = nums.size();
        while(missing <= n) {
            if(idx < k && nums[idx] <= missing) {
                missing += nums[idx++];
            }
            else {
                missing *= 2;
                patch++;
            }
        }
        return patch;
    }
};