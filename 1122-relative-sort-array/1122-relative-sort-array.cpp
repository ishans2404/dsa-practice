class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v(1001, 0);
        for(int i : arr1) v[i]++;
        arr1.clear();
        // int n = arr2.size();
        // for(int i=0; i<n; i++) 
        for(int i : arr2) {
            while(v[i] > 0) {
                arr1.push_back(i);
                v[i]--;
            }
        }
        for(int i=0; i<1001; i++) {
            if(v[i] > 0) {
                while(v[i] > 0) {
                    arr1.push_back(i);
                    v[i]--;
                }
            }
        }
        return arr1;
    }
};