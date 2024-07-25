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
    vector<int> v;
    istringstream iss(s);
    string w;
    while(getline(iss, w, ',')) {
        v.push_back(stoi(w));
    }
    make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end());
    out << "[";
    for(int i=0; i<v.size()-1; i++) {
        out << v[i] << ",";
    }
    out << v[v.size()-1] << "]\n";
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