/*
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
    while(getline(iss, word, ',')) {
        nums.push_back(stoi(word));
    }
    
    bool flag = false;
    int k = stoi(t);
    int n = nums.size();
    unordered_map<int, int> map;
    map[0] = -1;
    int cumsum = 0;

    for(int i=0; i<n; i++) {
        cumsum += nums[i];
        int rem = cumsum % k;

        if(map.find(rem) == map.end()) { // map[rem] not present
            map[rem] = i;
        }
        else {
            if(i - map[rem] > 1) {
                flag = true;
                goto label;
            }
        }
    }
    
    label:
    if(flag) out<<"true"<<endl;
    else out<<"false"<<endl;
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

*/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int prefixRem = 0;
        vector<int> v(k, 0);
        v[0] = 1;

        for(int i=0; i<n; i++) {
            prefixRem = (prefixRem + nums[i] % k + k) % k;
            res += v[prefixRem];
            v[prefixRem]++;
        }

        return res;
    }
};