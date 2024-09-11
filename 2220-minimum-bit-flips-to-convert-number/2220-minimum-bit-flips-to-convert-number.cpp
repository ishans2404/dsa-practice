class Solution {
public:
    int minBitFlips(int a, int b) {
        return bitset<32>(a^b).count();
    }
};