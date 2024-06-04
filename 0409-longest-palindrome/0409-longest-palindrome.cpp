#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    bitset<52> bit;
    int it = 1, n = s.length()-1;
    while(it < n) {
        if(s[it] >= 97) bit[s[it] - 97] = ~ bit[s[it] - 97];
        else bit[s[it] - 39] = ~ bit[s[it] - 39];
        it++;
    }
    int c = 0;
    for(int i=0; i<52; i++) if(bit[i]) c++;
    if(c == 0) out << n-1 << endl;
    else out << n-c << endl;
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
    int longestPalindrome(string s) {
        bitset<52> bit;
        int it = 0, n = s.length();
        while(it < n) {
            if(s[it] >= 97) bit[s[it] - 97] = ~ bit[s[it] - 97];
            else bit[s[it] - 39] = ~ bit[s[it] - 39];
        }
        int c = bit.count();
        if(c == 0) return n-1;
        return n-c;
    }
};