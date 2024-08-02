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
//         }
//         return res;
//     }
// };

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

int helper(vector<int>& nums) {
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

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    s.erase(s.begin());
    s.pop_back();
    string w;
    istringstream iss(s);
    vector<int> nums;
    while(getline(iss, w, ',')) {
        nums.push_back(stoi(w));
    }

    out << helper(nums) << endl;
}

bool Solve = [](){
    std::ofstream out("user.out");
    for (std::string s; std::getline(std::cin, s);) {
        parse_input_and_solve(out, s);
    }
    out.flush();
    exit(0);
    return true;
}();



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