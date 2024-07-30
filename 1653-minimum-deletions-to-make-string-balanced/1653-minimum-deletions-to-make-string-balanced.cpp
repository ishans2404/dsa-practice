class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0, ans = 0;
        for(char& c : s) {
            ans = min(ans += (c == 'a'), cnt += (c == 'b'));
        }
        return ans;
    }
};