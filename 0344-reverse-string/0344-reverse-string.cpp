class Solution {
public:
    void reverseString(vector<char>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int r = s.size()-1;
        if(r == 0) return;
        int l = 0;
        while(l < r) {
            char t = s[l];
            s[l++] = s[r];
            s[r--] = t;
        }
    }
};