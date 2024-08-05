class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        unordered_set<string> distinct, seen;
        for (const string& str : arr) {
            if (!seen.insert(str).second) {
                distinct.erase(str);
            } else {
                distinct.insert(str);
            }
        }
        for (const string& str : arr) {
            if (distinct.count(str) && --k == 0) {
                return str;
            }
        }
        return "";
    }
};