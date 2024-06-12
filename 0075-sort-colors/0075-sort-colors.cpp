class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, it = 0;
        while(it <= r) {
            if(nums[it] == 0) swap(nums[it++], nums[l++]);
            else if(nums[it] == 2) swap(nums[it], nums[r--]);
            else it++;
        }
    }
};