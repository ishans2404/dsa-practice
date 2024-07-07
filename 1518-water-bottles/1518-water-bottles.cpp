class Solution {
public:
    int numWaterBottles(int n, int e) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int c = 0;
        while(n >= e) {
            int k = n / e;
            c += e * k;
            n -= e * k;
            n += k;
        }
        return c+n;
    }
};