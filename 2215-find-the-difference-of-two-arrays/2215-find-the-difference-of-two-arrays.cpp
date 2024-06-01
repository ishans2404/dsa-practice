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
        vector<vector<int>> v(2, vector<int>());
        for(int i=0; i<2001; i++) {
            if(b1[i]) v[0].push_back(i-1000);
            else if(b2[i]) v[1].push_back(i-1000);
        }
        return v;
    }
};