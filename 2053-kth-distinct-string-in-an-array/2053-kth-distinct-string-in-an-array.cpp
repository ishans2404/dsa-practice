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
    int k = stoi(t);
    vector<string> arr;
    unordered_map<string, int> d;
    istringstream iss(s);
    string w;
    while(getline(iss, w, ',')) {
        w.erase(w.begin());
        w.pop_back();
        arr.push_back(w);
        d[w]++;
    }

    string ans = "";
    int count = 0;
    for(const auto& x : arr) {
        if(d[x] == 1) {
            ans = x;
            count++;
        }
        if(count == k) break;
    }

    out<<"\"";
    if(count == k) out<<ans;
    out<<"\""<<endl;
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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> d;
        for (const auto& x : arr) {
            d[x]++;
        }
        
        string ans = "";
        int count = 0;
        for (const auto& x : arr) {
            if (d[x] == 1) {
                ans = x;
                count++;
            }
            
            if (count == k) {
                return ans;
            }
        }
        return "";
    }
};