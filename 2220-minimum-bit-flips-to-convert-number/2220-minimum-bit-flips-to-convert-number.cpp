class Solution {
public:
    int minBitFlips(int start, int goal) {
        start ^= goal;
        int cnt = 0;
        while(start > 0) {
            cnt += start % 2;
            start = start >> 1;
        }
        return cnt;
    }
};