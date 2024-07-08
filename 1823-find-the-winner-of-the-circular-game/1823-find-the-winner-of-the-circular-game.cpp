#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    int n = stoi(s);
    int k = stoi(t);
    int winner = 0;
    for(int i = 1; i <= n; i++) {
        winner = (winner + k) % i;
    }
    out << winner + 1 << endl;
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
    int findTheWinner(int n, int k) {
        int winner = 0;
        for(int i = 1; i <= n; i++) {
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};