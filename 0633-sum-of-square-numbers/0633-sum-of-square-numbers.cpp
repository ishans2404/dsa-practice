class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int, int> ump;

        for(int i=0; i<=sqrt(c); i++){
            ump[i*i]++;
            int req = c - i*i;

            if(ump[req]){
                return true;
            }
        }

        return false;
    }
};