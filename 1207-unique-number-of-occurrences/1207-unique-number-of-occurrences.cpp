#include <bits/stdc++.h>
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> umap;
        for(auto i:arr) {
            if(umap.find(i) == umap.end()) umap[i] = 1;
            else umap[i]++;
        }
        arr.clear();
        for(auto it:umap) arr.push_back(it.second);
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-1; i++) {
            if(arr[i] == arr[i+1]) return false;
        }
        return true;
    }
};