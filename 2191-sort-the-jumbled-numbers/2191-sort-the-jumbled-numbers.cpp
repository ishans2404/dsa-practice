class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        vector<pair<int, int>> storePairs;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int val = 0;
            int num = nums[i];
            int ex = 1;

            if(num == 0) {
                storePairs.push_back({mapping[0], i});
                continue;
            }
            
            while(num != 0) {
                val += ex * mapping[num % 10];
                ex *= 10;
                num /= 10;
            }
            storePairs.push_back({val, i});
        }

        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for(auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};