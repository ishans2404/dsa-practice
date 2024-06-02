#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    int res = 0;
    s.erase(s.begin());
    s.pop_back();
    int n = s.size();
    for(int i=0; i<n-1; i++) res += abs(s[i]-s[i+1]);
    out<<res<<endl;
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
    int scoreOfString(string s) {
        int res = 0;    
        int n = s.size();
        for(int i=0; i<n-1; i++) res += abs(s[i]-s[i+1]);
        return res;
    }
};