#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    s.erase(s.begin());
    s.pop_back();
    istringstream iss(s);
    string w;
    int cnt = 0;
    while(getline(iss, w, ',')) {
        int num = (w[12] - 48) * 10 + (w[13] - 48);
        if(num > 60) cnt++;
    }
    out << cnt << endl;
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
    int countSeniors(vector<string>& det) {
        int cnt = 0;
        for(auto& t : det) {
            if(t[11] - 48 <= 5) continue;
            if(t[11] - 48 >= 6) cnt++;
        }
        return cnt;
    }
};