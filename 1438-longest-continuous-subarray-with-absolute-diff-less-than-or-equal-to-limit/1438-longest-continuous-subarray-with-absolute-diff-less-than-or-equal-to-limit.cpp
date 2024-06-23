#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    s.erase(s.begin());
    s.pop_back();
    vector<int> nums;
    istringstream iss(s);
    string w;
    while(getline(iss, w, ',')) nums.push_back(stoi(w));
    int limit = stoi(t);
    
    int l = 0, r = 0, res = 0, n = nums.size();
    deque<int> minm, maxm;
    while(r < n) {
        while(!minm.empty() && minm.back() > nums[r]) {
            minm.pop_back();
        }
        minm.push_back(nums[r]);

        while(!maxm.empty() && maxm.back() < nums[r]) {
            maxm.pop_back();
        }
        maxm.push_back(nums[r]);

        while(maxm.front() - minm.front() > limit) {
            if(nums[l] == maxm.front()) maxm.pop_front();
            if(nums[l] == minm.front()) minm.pop_front();
            l++;
        }
        res = max(res, r-l+1);
        r++;
    }
    out << res << endl;
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string s, t;
    while (std::getline(std::cin, s) && std::getline(std::cin, t)) {
        parse_input_and_solve(out, s, t);
    }
    out.flush();
    exit(0);
    return true;
}();



class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0, res = 0, n = nums.size();
        deque<int> minm, maxm;
        while(r < n) {
            while(!minm.empty() && minm.back() > nums[r]) {
                minm.pop_back();
            }
            minm.push_back(nums[r]);
            
            while(!maxm.empty() && maxm.back() < nums[r]) {
                maxm.pop_back();
            }
            maxm.push_back(nums[r]);

            while(maxm.front() - minm.front() > limit) {
                if(nums[l] == maxm.front()) maxm.pop_front();
                if(nums[l] == minm.front()) minm.pop_front();
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};