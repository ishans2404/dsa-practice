class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> freq(100001, 0);
        int minv = nums[0], maxv = nums[0], n = nums.size();
        for(int i : nums) {
            freq[i]++;
            minv = min(i, minv);
            maxv = max(i, maxv);
        }

        int c = 0, total = 0;
        for(int i=minv; i<=maxv; i++) {
            int f = freq[i];
            c = c + f - !!(c | f);  // !!(c | f) = 0 if both c, f are zero, else 1
            total += c;
            freq[i] = 0;
        }
        return int(total + c*(c-1)/2);
    }
};