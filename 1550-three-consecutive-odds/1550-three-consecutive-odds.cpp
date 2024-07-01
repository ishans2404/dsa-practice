class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int odd = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] & 1 == 1) {
                odd++;
                if(odd == 3) return true;
            }
            else odd = 0;
        }
        return false;
    }
};