class Solution {
private:
    vector<int> findOrder(int k, vector<vector<int>>& cond) {
        vector<vector<int>> adj(k+1);
        vector<int> indegree(k+1);

        for(auto i : cond) {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        queue<int> q;
        for(int i=1; i<=k; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int cnt = 0;
        vector<int> order;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            cnt++;
            order.push_back(curr);

            for(int neighbor: adj[curr]) {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if(cnt == k) return order;
        return {};
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowCond, vector<vector<int>>& colCond) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        vector<int> rowArr = findOrder(k, rowCond);
        vector<int> colArr = findOrder(k, colCond);

        if(rowArr.size() == 0 || colArr.size() == 0) return {};

        vector<pair<int, int>> ind(k);
        for(int i=0; i<k; i++) {
            ind[rowArr[i] - 1].first = i;
            ind[colArr[i] - 1].second = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for(int i=0; i<k; i++) {
            res[ind[i].first][ind[i].second] = i +1;
        }
        
        return res;
    }
};