class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        string ans = "";
        for(char c:s) {
            if(c == '*') {
                if(!ans.empty()) ans.pop_back();
            }
            else ans += c;
        }
        return ans;
    }
};