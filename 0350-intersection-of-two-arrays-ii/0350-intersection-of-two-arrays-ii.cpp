class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        for(int i : nums1) m[i]++;
        // int n = nums2.size();
        // for(int i=0; i<n; i++) {
        //     if(n)
        // }
        nums1.clear();
        for(int i : nums2) {
            if(m[i] > 0) {
                nums1.push_back(i);
                m[i]--;
            }
        }
        return nums1;
    }
};