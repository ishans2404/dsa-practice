class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int i = rowSum.size()-1, j = colSum.size()-1;
        vector<vector<int>> grid(i+1, vector<int>(j+1, 0));

        while(i>=0 && j >=0) {
            if(rowSum[i] <= colSum[j]) {
                grid[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                i--;
            }
            else {
                grid[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                j--;
            }
        }
        return grid;
    }
};