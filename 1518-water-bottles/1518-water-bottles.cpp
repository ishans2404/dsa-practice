#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    int n = stoi(s), e = stoi(t);
    int c = n;
    while(n >= e) {
        c += n / e;
        n = n / e + n % e;
    }
    out << c << endl;
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
    int numWaterBottles(int n, int e) {
        int c = n;
        while(n >= e) {
            c += n / e;
            n = n / e + n % e;
        }
        return c;
    }
};