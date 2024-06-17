class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> row;
        string temp;
        int n = grid.size();
        for(int i=0; i<n; i++){
            temp = "";
            for(int j=0; j<n; j++){
                temp += to_string(grid[i][j]) + " ";
            }
            row[temp]++;
        }
        int ans=0;
        for(int i=0; i<n; ++i){
            temp="";
            for(int j=0; j<n; j++){
                temp += to_string(grid[j][i]) + " ";
            }
            if(row[temp]) ans += row[temp];
        }
        return ans;
    }
};