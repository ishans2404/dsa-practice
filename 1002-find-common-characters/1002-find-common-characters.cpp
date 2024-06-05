#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();


void parse_input_and_solve(std::ofstream& out, std::string& s) {
    s = s.substr(1, s.length()-2);
    vector<string> res;
    istringstream iss(s);
    string word;
    while(getline(iss, word, ',')) res.push_back(word.substr(1, word.length()-2));

    vector<int> freq(26), minFreq(26, INT_MAX);
    for(auto& w:res) {
        fill(freq.begin(), freq.end(), 0);
        for(char& ch:w) freq[ch-97]++;
        for(int i=0; i<26; i++) {
            minFreq[i] = min(minFreq[i], freq[i]);
        }
    }
    
    s = "[";
    for(int i=0; i<26; i++) {
        for(int j=0; j<minFreq[i]; j++) {
            s += "\"" + string(1, char(i + 97)) + "\",";
        }
    }
    if(s.back() == ',') s.pop_back();
    s += "]";
    out << s << endl;
}

bool Solve = [](){
    std::ofstream out("user.out");
    for (std::string s; std::getline(std::cin, s);) {
        parse_input_and_solve(out, s);
    }
    out.flush();
    exit(0);
    return true;
}();



class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        array<char, 26> freq, minFreq;
        minFreq.fill(100);
        for(auto& w: words){
            freq.fill(0);
            for(char c: w) freq[c-'a']++;
            for(int i=0; i<26; i++)
                minFreq[i]=min(freq[i], minFreq[i]);
        }
        vector<string> ans;
        for(int i=0; i<26; i++){
            for(int j=0; j<minFreq[i]; j++)
                ans.push_back(string(1, i+'a'));
        }
        return ans;
    }
};
