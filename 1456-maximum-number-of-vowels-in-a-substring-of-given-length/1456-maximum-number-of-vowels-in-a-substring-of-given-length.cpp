class Solution {
public:
    int isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
        return 0;
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