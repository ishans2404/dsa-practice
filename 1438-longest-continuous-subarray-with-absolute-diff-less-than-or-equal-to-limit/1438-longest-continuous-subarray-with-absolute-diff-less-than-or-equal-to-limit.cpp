class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0, res = 0, n = nums.size();
        deque<int> minm, maxm;
        while(r < n) {
            while(!minm.empty() && minm.back() > nums[r]) {
                minm.pop_back();
            }
            minm.push_back(nums[r]);
            
            while(!maxm.empty() && maxm.back() < nums[r]) {
                maxm.pop_back();
            }
            maxm.push_back(nums[r]);

            while(maxm.front() - minm.front() > limit) {
                if(nums[l] == maxm.front()) maxm.pop_front();
                if(nums[l] == minm.front()) minm.pop_front();
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};