// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         int wndw = 0, n = nums.size();
//         for(auto& i : nums) wndw += i;

//         int res = 0, temp;
//         for(int i=0; i<wndw; i++) {
//             res += (nums[i] == 0);
//         }
//         temp = res;
//         for(int i=wndw; i<n+wndw; i++) {
//             if(nums[i-wndw] == 0) temp--;
//             if(nums[i%n] == 0) temp++;
//             res = min(res, temp);
//             cout<<res<<" ";
//         }
//         cout<<endl;
//         return res;
//     }
// };

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(auto& i : nums) ones += i;
        if(ones == 0 || ones == n) return 0;
        
        int cnt = 0; // 1st window
        for(int i = 0; i < ones; i++) cnt += nums[i];
        int res = cnt;
        for(int i = 0; i < n; i++) {
            cnt -= nums[i];
            cnt += nums[(i + ones) % n];
            res = max(res, cnt);
        }
        
        return ones - res;
    }
};