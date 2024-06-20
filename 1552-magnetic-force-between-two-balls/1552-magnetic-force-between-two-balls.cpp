class Solution {
public:
    bool possible(vector<int>& position, int m, int mid) {
        int n = position.size();
        int lastPos = position[0], balls = 1;
        for(int i=1; i<n; i++) {
            if(position[i] - lastPos >= mid) {
                balls++;   
                if(balls == m) return true;
                lastPos = position[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0, r = position[n-1] - position[0];
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(possible(position, m, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};