class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        auto [minimum, maximum] = minmax_element(nums.begin(), nums.end());
        int n = nums.size(), min = *minimum, max = *maximum;
        vector<int> freq(max-min + n+1, 0);
        for(int i : nums) freq[i-min]++;
        int count = 0, inc = 0;
        for(int i=0; count < n; i++) {
            int f = freq[i];
            count += (f != 0);
            if(f <= 1) continue;

            freq[i+1] += (f-1);
            inc += f-1;
        }
        return inc;
    }
};