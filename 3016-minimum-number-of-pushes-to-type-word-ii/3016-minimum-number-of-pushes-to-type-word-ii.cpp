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
    vector<int> vec(26, 0);
    for(auto& ch : s) vec[ch - 'a']++;
    sort(vec.begin(), vec.end(), greater<int>());
    int cnt = 0, res = 0;
    for(auto& it: vec) {
        if(cnt >= 0 && cnt <= 7) res += it;
        else if(cnt >= 8 && cnt <= 15) res += 2 * it;
        else if(cnt >= 16 && cnt <= 23) res += 3 * it;
        else res += 4 * it;
        cnt++;
    }
    out << res << endl;
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
    int minimumPushes(string word) {
        vector<int> vec(26, 0);
        for(auto& ch : word) vec[ch - 'a']++;
        sort(vec.begin(), vec.end(), greater<int>());
        int cnt = 0, res = 0;
        for(auto& it: vec) {
            if(cnt >= 0 && cnt <= 7) res += it;
            else if(cnt >= 8 && cnt <= 15) res += 2 * it;
            else if(cnt >= 16 && cnt <= 23) res += 3 * it;
            else res += 4 * it;
            cnt++;
        }
        return res;
    }
};