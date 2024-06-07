#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();


inline bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

std::array<int, 10000> nums;
void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    const int N = s.size();
    int left = 0;
    int idx = 0;
    while (left < N) {
        if (!is_digit(s[left])) {
            ++left;
            continue;
        }
        int right = left;
        int value = 0;
        while (right < N && is_digit(s[right])) {
            value = value * 10 + (s[right] - '0');
            ++right;
        }
        left = right;
        nums[idx] = value;
        ++idx;
    }
    
    bool flag = true;
    int groupSize = stoi(t);
    map<int, int> count;
    int start, curr;

    if(idx % groupSize != 0) {
        flag = false;
        goto label;
    }
    for(int i=0; i<idx; i++) count[nums[i]]++;

    while(!count.empty()) {
        start = count.begin()->first;
        for(int i=0; i<groupSize; i++) {
            curr = start + i;
            if(count[curr] == 0) {
                flag = false;
                goto label;
            }
            count[curr]--;
            if(count[curr] == 0) {
                count.erase(curr);
            }
        }
    }
    label:
    if(!flag) out<<"false"<<endl;
    else out<<"true"<<endl;
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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int, int> count;
        for(int i:hand) count[i]++;

        int start, curr;
        while(!count.empty()) {
            start = count.begin()->first;
            for(int i=0; i<groupSize; i++) {
                curr = start + i;
                if(count[curr] == 0) return false;
                count[curr]--;
                if(count[curr] == 0) {
                    count.erase(curr);
                }
            }
        }
        return true;
    }
};