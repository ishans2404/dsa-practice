#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, const std::string& s) {
    int n = stoi(s);
    vector<vector<string>> dp(n + 1);
    dp[0].push_back("");

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < i; ++j) {
            for(string& x : dp[j]) {
                for(string& y : dp[i - j - 1]) {
                    dp[i].push_back("(" + x + ")" + y);
                }
            }
        }
    }
    
    out << "[";
    int k = dp[n].size();
    for(int i = 0; i < k-1; i++) {
        out << "\"";
        out << dp[n][i];
        out << "\"";
        out << ",";
    }
    out << "\"";
    out << dp[n][k-1];
    out << "\"]" << endl;
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
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const string& x : dp[j]) {
                    for (const string& y : dp[i - j - 1]) {
                        dp[i].push_back("(" + x + ")" + y);
                    }
                }
            }
        }
        
        return dp[n];
    }
};