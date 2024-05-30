class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = nums.size();
        int rs = 0; // right sum
        int ls = 0; // left sum
        for(int i:nums) rs += i;
        int i = 0;
        while(i < n) {
            rs -= nums[i];
            if(ls == rs) return i;
            ls += nums[i++];
        }
        return -1;
    }
};