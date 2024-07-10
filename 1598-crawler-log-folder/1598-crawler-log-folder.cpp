class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c = 0, n = logs.size();
        for(auto& s : logs) {
            if(s == "./") continue;
            else if(s == "../") c = (c>0)? c-1 : c;
            else c++;
        }
        return c;
    }
};