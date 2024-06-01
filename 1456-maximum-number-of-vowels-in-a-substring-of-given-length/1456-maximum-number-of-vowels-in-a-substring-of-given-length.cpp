class Solution {
public:
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        bitset<122> alph;
        alph.set(97);
        alph.set(101);
        alph.set(105);
        alph.set(111);
        alph.set(117);
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