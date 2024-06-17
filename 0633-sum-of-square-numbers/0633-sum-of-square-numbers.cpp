class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c <= 2) return true;
        int st = sqrt(c);
        for(long i=0; i<=st; i++) {
            double t = sqrt(c - i * i);
            if(t == floor(t)) return true;
        }
        return false;
    }
};