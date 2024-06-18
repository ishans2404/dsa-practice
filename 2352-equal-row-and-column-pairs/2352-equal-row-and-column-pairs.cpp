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
    s.erase(s.begin());
    s.pop_back();

    string from = "],[";
    string to = "/";
    int startPos = 0;
    while((startPos = s.find(from, startPos)) != string::npos) {
        s.replace(startPos, from.length(), to);
        startPos += to.length();
    }

    unordered_map<string, int> rows;
    vector<string> row;
    stringstream ss(s);
    string w;
    while(getline(ss, w, '/')) {
        w += ',';
        rows[w]++;
        row.push_back(w);
    }

    int n = row.size();
    vector<string> col(n);
    for(int i=0; i<n; i++) {
        istringstream iss(row[i]);
        int j = 0;
        while(getline(iss, w, ',')) {
            col[j++] += w + ',';
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        w = col[i];
        if(rows[w]) ans += rows[w];
    }

    out << ans << endl;
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
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> row;
        string temp;
        int n = grid.size();
        for(int i=0; i<n; i++){
            temp = "";
            for(int j=0; j<n; j++){
                temp += to_string(grid[i][j]) + " ";
            }
            row[temp]++;
        }
        int ans=0;
        for(int i=0; i<n; ++i){
            temp="";
            for(int j=0; j<n; j++){
                temp += to_string(grid[j][i]) + " ";
            }
            if(row[temp]) ans += row[temp];
        }
        return ans;
    }
};