#include<bits/stdc++.h>
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
    map<int, int> m;
    istringstream iss(s);
    string w;
    int n = 0, k = 0;
    while(getline(iss, w, ',')) {
        m[stoi(w)]++;
        n++;
    }
    out << "[";
    for(auto& it:m) {
        for(int i=0; i<it.second; i++) {
            k++;
            if(k != n) out << it.first << ",";
            else out << it.first;
        }
    }
    out << "]\n";
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
    vector<int> sortArray(vector<int>& n) {
        
        make_heap(n.begin(), n.end());
        sort_heap(n.begin(), n.end());
        return n;
    }
};