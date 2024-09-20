#include <string> 

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.length();
        for(int i=0; i<=n; i++) {
            if(s.rfind(rev.substr(i, n-i), 0) == 0) {
                return rev.substr(0, i) + s;
            }
        }
        return "";
    }
};
