#include<bits/stdc++.h>
#define M 10001
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& a, std::string& s, std::string& b) {
    s[0] = ',';
    s.pop_back();
    int n = stoi(a);
    int thresh = stoi(b);

    vector<vector<int>> graph(n, vector<int>(n, M));
    for(int i=0; i<n; i++) {
        graph[i][i] = 0;
    }

    istringstream iss(s);
    string row;
    vector<int> it;
    while(getline(iss, row, ']')) {
        row.erase(row.begin());
        row.erase(row.begin());
        istringstream ss(row);
        string w;
        while(getline(ss, w, ',')) {
            it.push_back(stoi(w));
        }
        graph[it[0]][it[1]] = it[2];
        graph[it[1]][it[0]] = it[2];
        it.clear();
    }
    
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int minReachCities = n;
    int res = -1;

    for(int i=0; i<n; i++) {
        int reachCities = 0;
        for(int j=0; j<n; j++) {
            if(graph[i][j] <= thresh) reachCities++;
        }
        if(reachCities <= minReachCities) {
            minReachCities = reachCities;
            res = i;
        }
    }

    out << res << endl;
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string s, a, b;
    while (std::getline(std::cin, a) && std::getline(std::cin, s) && std::getline(std::cin, b)) {
        parse_input_and_solve(out, a, s, b);
    }
    out.flush();
    exit(0);
    return true;
}();



class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        vector<vector<int>> graph(n, vector<int>(n, M));
        for(int i=0; i<n; i++) {
            graph[i][i] = 0;
        }
        for(auto& it:edges) {
            graph[it[0]][it[1]] = it[2];
            graph[it[1]][it[0]] = it[2];
        }
        
        for(int k=0; k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int minReachCities = n;
        int res = -1;

        for(int i=0; i<n; i++) {
            int reachCities = 0;
            for(int j=0; j<n; j++) {
                if(graph[i][j] <= thresh) reachCities++;
            }
            if(reachCities <= minReachCities) {
                minReachCities = reachCities;
                res = i;
            }
        }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(graph[i][j] == M) cout << "inf";
        //         else cout << graph[i][j];
        //         cout << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }
};