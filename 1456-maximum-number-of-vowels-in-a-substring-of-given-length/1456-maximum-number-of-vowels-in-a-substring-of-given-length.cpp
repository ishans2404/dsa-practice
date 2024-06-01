class Solution {
public:
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<bool> alph(122, false);
        alph[97] = 1;
        alph[101] = 1;
        alph[105] = 1;
        alph[111] = 1;
        alph[117] = 1;
        int vowel = 0, n = s.length();
        for(int i=0; i<k; i++) vowel += alph[s[i]];
        int maxVowel = vowel;
        for(int i=k; i<n; i++) {
            vowel += alph[s[i]] - alph[s[i-k]];
            maxVowel = max(maxVowel, vowel);
        }
        return maxVowel;
    }
};