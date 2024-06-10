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
    vector<int> heights, exp;
    istringstream iss(s);
    string word;
    int k;
    while(getline(iss, word, ',')) {
        k = stoi(word);
        heights.push_back(k);
        exp.push_back(k);
    }
    
    k = 0;
    int n = heights.size();
    sort(exp.begin(), exp.end());
    for(int i=0; i<n; i++) {
        if(exp[i] != heights[i]) k++;
    }
    out << k << endl;
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
    int heightChecker(vector<int>& heights) {
        int c = 0;
        int n = heights.size();
        vector<int> exp(n);
        for(int i=0; i<n; i++) exp[i] = heights[i];
        sort(exp.begin(), exp.end());
        for(int i=0; i<n; i++) {
            if(exp[i] != heights[i]) c++;
        }
        return c;
    }
};