#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t, std::string& q) {
    s.erase(s.begin());
    s.pop_back();
    int m = stoi(t);
    int k = stoi(q);
    vector<int> bloomDay;
    istringstream iss(s);
    string w;
    while(getline(iss, w, ',')) bloomDay.push_back(stoi(w));
    
    int l = *min_element(bloomDay.begin(), bloomDay.end()), r = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    int n = bloomDay.size();
    if((long long)m*k > n) goto lab;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int con = 0, boq = 0; // consecutiveLength, bouquets
        for(int i=0; i<n; i++) {
            if(bloomDay[i] <= mid) con++;
            else con = 0;
            if(con >= k) {
                con = 0; 
                boq++;
            }
        }
        if(boq >= m) {
            ans = mid;
            r = mid - 1; // update r to find minimum ans
        }
        else l = mid + 1; // update l to find answer
    }
    
    lab:
    out << ans << endl;
    
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string s, t, q;
    while (std::getline(std::cin, s) && std::getline(std::cin, t) && std::getline(std::cin, q)) {
        parse_input_and_solve(out, s, t, q);
    }
    out.flush();
    exit(0);
    return true;
}();




class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 0, r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        int n = bloomDay.size();
        if((long long)m*k > n) return ans;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int con = 0, boq = 0; // consecutiveLength, bouquets
            for(int i=0; i<n; i++) {
                if(bloomDay[i] <= mid) con++;
                else con = 0;
                if(con >= k) {
                    con = 0; 
                    boq++;
                }
            }
            if(boq >= m) {
                ans = mid;
                r = mid - 1; // update r to find minimum ans
            }
            else l = mid + 1; // update l to find answer
        }
        return ans;
    }
};