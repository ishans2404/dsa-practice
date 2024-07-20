class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> grid(n, vector<int>(m, 0));
        int i = 0, j = 0;

        while(i < n && j < m) {
            int elem = min(rowSum[i], colSum[j]);
            grid[i][j] = elem;
            rowSum[i] -= elem;
            colSum[j] -= elem;
            i += (rowSum[i] == 0);
            j += (colSum[j] == 0);
        }
        return grid;
    }
};