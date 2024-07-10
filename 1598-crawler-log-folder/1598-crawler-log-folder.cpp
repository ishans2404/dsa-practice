class Solution {
public:
    int minOperations(vector<string>& logs) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int c = 0;
        for(auto& s : logs) {
            if(s == "./") continue;
            else if(s == "../") c = (c>0)? c-1 : c;
            else c++;
        }
        return c;
    }
};