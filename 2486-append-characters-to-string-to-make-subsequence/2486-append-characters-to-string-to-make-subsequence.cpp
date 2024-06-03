#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    s.erase(s.begin());
    s.pop_back();
    t.erase(t.begin());
    t.pop_back();
    int n = s.length();
    int m = t.length();
    int len = 0;
    int it = 0;
    while(it < n && len < m) {
        if(s[it] == t[len]) len++;
        it++;
    }
    if(len == m) out<<"0"<<endl;
    else out<<m-len<<endl;
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string s, t;
    while (std::getline(std::cin, s) && std::getline(std::cin, t)) {
        parse_input_and_solve(out, s, t);
    }
    out.flush();
    exit(0);
    return true;
}();



class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        int len = 0;
        int it = 0;
        while(it < n && len < m) {
            if(s[it] == t[len]) len++;
            it++;
        }
        if(len == m) return 0;
        return m-len;
    }
};