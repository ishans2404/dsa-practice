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
    int n = stoi(t);
    vector<int> nums;
    string w;
    istringstream iss(s);
    while(getline(iss, w, ',')) nums.push_back(stoi(w));

    long long missing = 1;
    int patch = 0;
    int idx = 0;
    int k = nums.size();
    while(missing <= n) {
        if(idx < k && nums[idx] <= missing) {
            missing += nums[idx++];
        }
        else {
            missing *= 2;
            patch++;
        }
    }
    out << patch << endl;
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
    int minPatches(vector<int>& nums, int n) {
        long long missing = 1;
        int patch = 0;
        int idx = 0;
        int k = nums.size();
        while(missing <= n) {
            if(idx < k && nums[idx] <= missing) {
                missing += nums[idx++];
            }
            else {
                missing *= 2;
                patch++;
            }
        }
        return patch;
    }
};