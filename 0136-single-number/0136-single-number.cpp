#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

inline bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

std::array<int, 100000> nums;
void parse_input_and_solve(std::ofstream& out, const std::string& s) {
    const int N = s.size();
    int left = 0;
    int idx = 0;
    while (left < N) {
        if (!isdigit(s[left]) && !(s[left] == '-' && left + 1 < N && isdigit(s[left + 1]))) {
            ++left;
            continue;
        }
        int right = left;
        int value = 0;
        bool negative = false;

        if (s[right] == '-') {
            negative = true;
            ++right;
        }
        while(right < N && isdigit(s[right])) {
            value = value * 10 + (s[right] - '0');
            ++right;
        }

        if(negative) value = -value;
        left = right;
        nums[idx++] = value;
    }
    // out << "[";
    // const int M = idx;
    bitset<60001> b;
    for(int i=0; i<idx; i++) {
        b[nums[i]+30000] = ~b[nums[i]+30000];
    }
    for(int i=0; i<60001; i++) {
        if(b[i]) {
            out << i-30000 << "\n";
            break;
        }
    }
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
    int singleNumber(vector<int>& nums) {
        bitset<60001> b;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            b[nums[i]+30000] = ~b[nums[i]+30000];
        }
        for(int i=0; i<60001; i++) {
            if(b[i]) return i-30000;
        }
        return -1;
    }
};