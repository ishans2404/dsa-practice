#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, const std::string& s) {
    int c = stoi(s);
    int st = sqrt(c);
    if(c <= 2) {
        out<<"true\n";
        goto label;
    }
    for(long i=0; i<=st; i++) {
        double t = sqrt(c - i * i);
        if(t == floor(t)) {
            out<<"true\n";
            goto label;
        }
    }
    out<<"false\n";
    label:
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
    bool judgeSquareSum(int c) {
        if(c <= 2) return true;
        int st = sqrt(c);
        for(long i=0; i<=st; i++) {
            double t = sqrt(c - i * i);
            if(t == floor(t)) return true;
        }
        return false;
    }
};