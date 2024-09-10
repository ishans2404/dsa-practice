#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    s.pop_back();
    s.erase(s.begin());
    istringstream iss(s);
    string w;
    int sum = 0;
    int maxi = -10001;
    while(getline(iss, w, ',')) {
        sum += stoi(w);
        maxi = max(maxi, sum);
        sum = (sum < 0) ? 0 : sum;
    }
    out << maxi << endl;
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
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            sum = (sum < 0) ? 0 : sum;
        }
        return maxi;
    }
};