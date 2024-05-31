class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int n = nums.size();
        if(n == 1) return;
        int i = 0;
        while(i<n) {
            if(nums[i] != 0) i++;
            else break;
        }
        int j = i+1;
        while(j<n) {
            if(nums[j] != 0) {
                nums[i++] = nums[j];
                nums[j] = 0;
            }
            j++;
        }
    }
};