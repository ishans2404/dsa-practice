class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<string> row(n), col(n);
        string rstr, cstr;
        for(int i=0; i<n; i++) {
            cstr = "";
            rstr = "";
            for(int j=0; j<n; j++) {
                rstr += to_string(grid[i][j]) + " ";
                cstr += to_string(grid[j][i]) + " ";
            }
            row[i] = rstr;
            col[i] = cstr;
        }
        int c = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(row[i].length() == col[j].length()) {
                    if(row[i].compare(col[j]) == 0) c++;
                }
            }
        }
        return c;
    }
};