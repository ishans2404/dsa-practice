class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = -1;
        int cumsum = 0;

        for(int i=0; i<n; i++) {
            cumsum += nums[i];
            int rem = cumsum % k;

            if(map.find(rem) == map.end()) { // map[rem] not present
                map[rem] = i;
            }
            else {
                if(i - map[rem] > 1) {
                    return true;
                }
            }
        }

        return false;
    }
};