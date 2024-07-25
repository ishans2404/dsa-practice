#include<bits/stdc++.h>

class Solution {
public:
    vector<int> sortArray(vector<int>& n) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        make_heap(n.begin(), n.end());
        sort_heap(n.begin(), n.end());
        return n;
    }
};