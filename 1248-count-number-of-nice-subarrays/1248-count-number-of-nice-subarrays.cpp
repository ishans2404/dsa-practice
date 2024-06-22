class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), count = 0, ans = 0;
        while(r < n) {
            if(nums[r] % 2 != 0) {
                k--;
                count = 0;
            }
            while(k == 0) {
                if(nums[l] % 2 != 0) k++;
                count++;
                l++;
            }
            ans += count;
            r++;
        }
        return ans;
    }
};