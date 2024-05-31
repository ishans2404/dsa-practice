class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int m = *max_element(candies.begin(), candies.end());
        vector<bool> v;
        for(int& it:candies) {
            it += extraCandies;
            if(it >= m) v.push_back(true);
            else v.push_back(false);
        }
        return v;
    }
};