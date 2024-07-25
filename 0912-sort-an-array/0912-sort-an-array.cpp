#include<bits/stdc++.h>

class Solution {
public:
    vector<int> sortArray(vector<int>& n) {
        
        make_heap(n.begin(), n.end());
        sort_heap(n.begin(), n.end());
        return n;
    }
};