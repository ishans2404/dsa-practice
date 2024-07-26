#include<bits/stdc++.h>
#define M 10001
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