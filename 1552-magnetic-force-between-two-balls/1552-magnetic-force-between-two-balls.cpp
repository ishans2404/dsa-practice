class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0, r = position[n-1] - position[0];
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int lastPos = position[0], balls = 1;
            for(int i=1; i<n; i++) {
                if(position[i] - lastPos >= mid) {
                    lastPos = position[i];
                    balls++;   
                }
            }
            if(balls >= m) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};