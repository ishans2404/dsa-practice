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
    priority_queue<int, vector<int>, greater<int>> pq; 
    istringstream iss(s);
    string w;
    int n = 0, k = 0;
    while(getline(iss, w, ',')) {
        pq.push(stoi(w));
        n++;
    }
    out << "[";
    while(!pq.empty()) {
        k++;
        if(k != n) out << pq.top() << ",";
        else out << pq.top();
        pq.pop();
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