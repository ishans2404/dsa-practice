class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int alt = 0, sum = 0;
        for(auto i:gain) {
            sum += i;
            alt = max(alt, sum);
        }
        return alt;
    }
};