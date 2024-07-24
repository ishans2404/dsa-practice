class Solution {
public:
    int convert(int n, vector<int>& map) {
        int z = 0, ex = 1;
        while(n > 0) {
            z += map[n % 10] * ex;
            ex *= 10;
            n /= 10;
        }
        return z;
    } 
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int n = nums.size();
        if(n == mapping.size()) {
            string a = "", b = "";
            for(int i=0; i<n; i++) {
                a += to_string(mapping[i]);
                b += to_string(nums[i]);
            }
            if(a == b) return mapping;
            reverse(b.begin(), b.end());
            if(a == b) return mapping;
        }
        vector<vector<int>> map(n, vector<int>(3));
        for(int i=0; i<n; i++) {
            map[i] = {convert(nums[i], mapping), i, nums[i]};
        }
        sort(map.begin(), map.end());
        for(int i=0; i<n; i++) nums[i] = map[i][2];

        return nums;
    }
};