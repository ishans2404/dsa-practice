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
    vector<int> nums;
    istringstream iss(s);
    string word;
    while(getline(iss, word, ',')) {
        nums.push_back(stoi(word));
    }

    int n = nums.size(), c = 0, t;
    if(n == 1) {
        out << "0\n";
        goto label;
    }

    for(int i=1; i<n; i++) {
        if(nums[i] <= nums[i-1]) {
            t = nums[i-1] - nums[i] + 1;
            nums[i] += t;
            c += t;
        }
    }
    
    out << c << endl;
    label:
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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int c = 0, t;
        for(int i=1; i<n; i++) {
            if(nums[i] <= nums[i-1]) {
                t = nums[i-1] - nums[i] + 1;
                nums[i] += t;
                c += t;
            }
        }
        return c;
    }
};