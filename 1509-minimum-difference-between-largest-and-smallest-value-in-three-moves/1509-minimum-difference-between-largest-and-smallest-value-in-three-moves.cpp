#include <algorithm>

template<typename T>
T min(T a, T b, T c, T d, T e) {
    return min(min(min(min(a, b), c), d), e);
}

class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        if(n <= 4) return 0;
        
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
        
        for(int i : arr) {
            if(i < min1) {
                min4 = min3;
                min3 = min2;
                min2 = min1;
                min1 = i;
            } 
            else if(i < min2) {
                min4 = min3;
                min3 = min2;
                min2 = i;
            } 
            else if(i < min3) {
                min4 = min3;
                min3 = i;
            }
            else if(i < min4) {
                min4 = i;
            }
            
            if(i > max1) {
                max4 = max3;
                max3 = max2;
                max2 = max1;
                max1 = i;
            } 
            else if(i > max2) {
                max4 = max3;
                max3 = max2;
                max2 = i;
            } 
            else if(i > max3) {
                max4 = max3;
                max3 = i;
            }
            else if(i > max4) {
                max4 = i;
            }
        }

        int val = INT_MAX;
        val = min(val, max4 - min1, max1 - min4, max2 - min3, max3 - min2);  
        // remove last 3, remove first 3, remove first 2 last 1, remove first 1 last 2
        return val;
    }
};