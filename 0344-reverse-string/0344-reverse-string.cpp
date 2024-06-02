#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

inline bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

std::array<int, 100000> nums;
void parse_input_and_solve(std::ofstream& out, std::string& s) {
    s.erase(s.begin());
    s.pop_back();
    istringstream iss(s);
    string word;
    vector<string> res;
    while (getline(iss, word, ',')) {
        res.push_back(word);
    }
    out<<"[";
    for(int i=res.size()-1; i>=1; i--) out<<res[i]<<",";
    out<<res[0]<<"]\n";
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
    void reverseString(vector<char>& s) {
        
    }
};