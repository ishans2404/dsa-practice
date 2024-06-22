#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

int f(vector<int>& nums, int goal) {
    int l = 0, r = 0, n = nums.size(), sum = 0, c = 0;
    while(r < n) {
        sum += nums[r];
        while(l <= r && sum > goal) {
            sum -= nums[l++];
        }
        c += r++ - l;
    }
    return c;
}

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    s.erase(s.begin());
    s.pop_back();
    int goal = stoi(t);
    vector<int> nums;
    string w;
    istringstream iss(s);
    while(getline(iss, w, ',')) nums.push_back(stoi(w));
    
//     int temp;
    
//     int l = 0, r = 0, n = nums.size(), sum = 0, c = 0;
//     while(r < n) {
//         sum += nums[r];
//         while(l <= r && sum > goal) {
//             sum -= nums[l++];
//         }
//         c += r++ - l;
//     }
//     temp = c;
//     goal--;
    
//     l = 0, r = 0, sum = 0, c = 0;
//     while(r < n) {
//         sum += nums[r];
//         while(l <= r && sum > goal) {
//             sum -= nums[l++];
//         }
//         c += r++ - l;
//     }
    
//     out << temp - c << endl;
    
    out << f(nums, goal) - f(nums, goal-1) << endl;
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
    int function(vector<int>& nums, int goal) {
        int l = 0, r = 0, n = nums.size(), sum = 0, c = 0;
        while(r < n) {
            sum += nums[r];
            while(l <= r && sum > goal) {
                sum -= nums[l++];
            }
            c += r++ - l;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return function(nums, goal) - function(nums, goal-1);
    }
};