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
    vector<int> arr;
    string w;
    istringstream iss(s);
    
    bool flag = false;
    int odd = 0;
    while(getline(iss, w, ',')) {
        if(w.back() & 1 == 1) {
            odd++;
            if(odd == 3) {
                flag = true;
                goto label;
            }
        }
        else odd = 0;
    }
    label:
    if(flag) out<<"true\n";
    else out<<"false\n";
    
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
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int odd = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] & 1 == 1) {
                odd++;
                if(odd == 3) return true;
            }
            else odd = 0;
        }
        return false;
    }
};