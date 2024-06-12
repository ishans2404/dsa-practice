#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    s.erase(s.begin());
    s.pop_back();
    int l = 0, r = s.length()-1, it = 0;
    while(it <= r) {
        if(s[it] == '0') {
            s[it] = s[l];
            s[l] = '0';
            it += 2;
            l += 2;
        }
        else if(s[it] == '2') {
            s[it] = s[r];
            s[r] = '2';
            r -= 2;
        }
        else it += 2;
    }
    out<<"["<<s<<"]\n";
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
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1, it = 0;
        while(it <= r) {
            if(nums[it] == 0) swap(nums[it++], nums[l++]);
            else if(nums[it] == 2) swap(nums[it], nums[r--]);
            else it++;
        }
    }
};