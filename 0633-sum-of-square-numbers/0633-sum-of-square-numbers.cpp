class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0 || c == 1 || c == 2) return true;
        long l = 0, r = int(sqrt(c)) + 1;
        while(l <= r) {
            long num = l*l + r*r;
            if(num == c) return true;
            else if(num > c) r--;
            else l++;
        }
        return false;
    }
};