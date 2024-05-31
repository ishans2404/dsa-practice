#include <bits/stdc++.h>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> umap;
        unordered_set<int> occurrences;

        for(auto i:arr) umap[i]++;
        for(auto it:umap) {
            if(!occurrences.insert(it.second).second) return false;
        }
        return true;
    }
};