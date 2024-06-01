#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        bitset<2001> b1, b2, temp;
        for(int n:nums1) b1.set(n+1000);
        for(int n:nums2) b2.set(n+1000);
        temp = b1;
        b1 = b1 & ~b2;
        b2 = b2 & ~temp;
        vector<int> v1, v2;
        for(int i=0; i<2001; i++) {
            if(b1[i]) v1.push_back(i-1000);
            else if(b2[i]) v2.push_back(i-1000);
        }
        vector<vector<int>> v = {v1, v2};
        return v;
    }
};