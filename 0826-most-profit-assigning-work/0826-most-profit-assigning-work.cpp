class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<vector<int>> vec(n);
        for(int i=0; i<n; i++) {
            vec[i] = {difficulty[i], profit[i]};
        }

        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, bestProfit = 0, idx = 0;

        for(int i=0; i<m; i++) {
            while(idx < n && worker[i] >= vec[idx][0]) {
                bestProfit = max(bestProfit, vec[idx][1]);
                idx++;
            }
            maxProfit += bestProfit;
        }
        return maxProfit;
    }
};