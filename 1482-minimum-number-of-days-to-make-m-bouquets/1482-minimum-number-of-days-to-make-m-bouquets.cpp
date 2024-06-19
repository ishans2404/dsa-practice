class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        int n = bloomDay.size();
        if((long long)m*k > n) return ans;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int con = 0, boq = 0; // consecutiveLength, bouquets
            for(int i=0; i<n; i++) {
                if(bloomDay[i] <= mid) con++;
                else con = 0;
                if(con >= k) {
                    con = 0; 
                    boq++;
                }
            }
            if(boq >= m) {
                ans = mid;
                r = mid - 1; // update r to find minimum ans
            }
            else l = mid + 1; // update l to find answer
        }
        return ans;
    }
};