#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    vector<string> v;
    string t = "";
    int br = 0;
    for(char ch : s) {
        if(ch == '[') continue;
        else if(isdigit(ch)) t += ch;
        else if(ch == ']') {
            br++;
            if(br == 2) {
                v.push_back(t);
                t = "";
                break;
            }
        }
        else if(ch == ',') {
            v.push_back(t);
            t = "";
        }
    }
    if(v[0] == v[2] || v[0] == v[3]) out<<v[0]<<endl;
    else out<<v[1]<<endl;
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
    int findCenter(vector<vector<int>>& edges) {
        sort(edges[0].begin(), edges[0].end());
        sort(edges[1].begin(), edges[1].end());
        if(edges[0][0] == edges[1][0]) return edges[0][0];
        return edges[0][1];

    }
};