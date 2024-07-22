#include <execution>
using namespace std;
static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> pairs{};
        for(size_t i = 0; i < names.size(); i++)
            pairs.push_back(make_pair(names[i], heights[i]));

        sort(execution::par_unseq, pairs.begin(), pairs.end(), [](const auto& a, const auto& b) -> bool
        {
            return a.second > b.second;
        });

        int i = 0;
        for(const auto& p : pairs)
            names[i++] = p.first;

        return names;
    }
};