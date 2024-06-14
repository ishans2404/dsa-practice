class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        bitset<200000> b;
        int n = nums.size(), c = 0;
        for(int i=0; i<n; i++) {
            int val = nums[i];
            if(!b[val]) b.set(val);
            else {
                while(b[val]) {
                    val++;
                    c++;
                }
                b.set(val);
            }
        }
        return c;
    }
};