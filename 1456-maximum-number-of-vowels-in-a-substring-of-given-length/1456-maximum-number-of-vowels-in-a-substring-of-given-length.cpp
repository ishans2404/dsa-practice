class Solution {
public:
    bool isVowel(char c) {
        static const bool vowelLookupTable[256] = {
            ['a'] = true, ['e'] = true, ['i'] = true, ['o'] = true, ['u'] = true
        };
        return vowelLookupTable[static_cast<unsigned char>(c)];
    }
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int vowel = 0, n = s.length();
        for(int i=0; i<k; i++) vowel += isVowel(s[i]);
        int maxVowel = vowel;
        for(int i=k; i<n; i++) {
            vowel += isVowel(s[i]) - isVowel(s[i-k]);
            maxVowel = max(maxVowel, vowel);
        }
        return maxVowel;
    }
};