class Solution {
public:
    int numWaterBottles(int n, int e) {
        int c = n;
        while(n >= e) {
            c += n / e;
            n = n / e + n % e;
        }
        return c;
    }
};