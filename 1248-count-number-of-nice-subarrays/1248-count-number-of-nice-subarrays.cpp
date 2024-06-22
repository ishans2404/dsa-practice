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
    string word;
    while (getline(iss, word, ',')) {
        nums.push_back(stoi(word));
    }
    int k = stoi(t);

    int l = 0, r = 0, n = nums.size(), count = 0, ans = 0;
    while(r < n) {
        if(nums[r] % 2 != 0) {
            k--;
            count = 0;
        }
        while(k == 0) {
            if(nums[l] % 2 != 0) k++;
            count++;
            l++;
        }
        ans += count;
        r++;
    }
    out << ans << endl;
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), count = 0, ans = 0;
        while(r < n) {
            if(nums[r] % 2 != 0) {
                k--;
                count = 0;
            }
            while(k == 0) {
                if(nums[l] % 2 != 0) k++;
                count++;
                l++;
            }
            ans += count;
            r++;
        }
        return ans;
    }
};