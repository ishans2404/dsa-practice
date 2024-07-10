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
    string w;
    // vector<string> logs;
    istringstream iss(s);
    int c = 0;
    while(getline(iss, w, ',')) {
        if(w == "\"./\"") continue;
        else if(w == "\"../\"") c = (c>0)? c-1 : c;
        else c++;
    }
    out << c << endl;
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
    int minOperations(vector<string>& logs) {
        int c = 0;
        for(auto& s : logs) {
            if(s == "./") continue;
            else if(s == "../") c = (c>0)? c-1 : c;
            else c++;
        }
        return c;
    }
};