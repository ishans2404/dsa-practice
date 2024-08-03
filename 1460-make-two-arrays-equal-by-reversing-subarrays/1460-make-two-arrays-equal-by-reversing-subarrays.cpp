class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<vector<int>> v(1001, vector<int>(2, 0));
        for(auto& i : target) v[i][0]++;
        for(auto& i : arr) v[i][1]++;
        for(int i=1; i<1001; i++) {
            if(v[i][0] != v[i][1]) return false;
        }
        return true;
    }
};