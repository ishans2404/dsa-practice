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
    int minv = INT_MAX, maxv = INT_MIN;
    while(getline(iss, word, ',')) {
        int w = stoi(word);
        nums.push_back(w);
        minv = min(minv, w);
        maxv = max(maxv, w);
    }

    int n = nums.size();
    vector<int> freq(maxv - minv + n+1, 0);
    for(int i : nums) freq[i-minv]++;
    int count = 0, inc = 0;
    for(int i=0; count < n; i++) {
        int f = freq[i];
        count += (f != 0);
        if(f <= 1) continue;

        freq[i+1] += (f-1);
        inc += f-1;
    }

    out<<inc<<endl;
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
    int minIncrementForUnique(vector<int>& nums) {
        auto [minimum, maximum] = minmax_element(nums.begin(), nums.end());
        int n = nums.size(), min = *minimum, max = *maximum;
        vector<int> freq(max-min + n+1, 0);
        for(int i : nums) freq[i-min]++;
        int count = 0, inc = 0;
        for(int i=0; count < n; i++) {
            int f = freq[i];
            count += (f != 0);
            if(f <= 1) continue;

            freq[i+1] += (f-1);
            inc += f-1;
        }
        return inc;
    }
};