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
    t += ',';
    vector<int> deg(n, 0);
    string w = "";
    for(char c:t) {
        if(isdigit(c)) w += c;
        else if(c == '[' || c == ']') continue;
        else {
            deg[stoi(w)]++;
            w = "";
        }
    }
    sort(deg.begin(), deg.end());
    long long ans=0;
    for(int i=0; i<n; i++)
        ans += (i+1LL) * deg[i];
    out << ans << endl;
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
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        for(auto& e: roads){
            deg[e[0]]++;
            deg[e[1]]++;
        }
        sort(deg.begin(), deg.end());
        long long ans=0;
        for(int i=0; i<n; i++)
            ans += (i+1LL) * deg[i];
        return ans;
    }
};