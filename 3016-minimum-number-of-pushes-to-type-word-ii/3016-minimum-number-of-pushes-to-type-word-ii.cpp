class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> map;
        for(auto& c : word) map[c]++;
        vector<pair<char, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });
        int cnt = 0, res = 0;
        for(auto& it: vec) {
            if(cnt >= 0 && cnt <= 7) res += it.second;
            else if(cnt >= 8 && cnt <= 15) res += 2 * it.second;
            else if(cnt >= 16 && cnt <= 23) res += 3 * it.second;
            else res += 4 * it.second;
            cnt++;
        }
        return res;
    }
};