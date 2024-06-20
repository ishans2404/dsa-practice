#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

bool possible(vector<int>& position, int m, int mid) {
    int n = position.size();
    int lastPos = position[0], balls = 1;
    for(int i=1; i<n; i++) {
        if(position[i] - lastPos >= mid) {
            balls++;   
            if(balls == m) return true;
            lastPos = position[i];
        }
    }
    return false;
}

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    s.erase(s.begin());
    s.pop_back();
    int m = stoi(t);
    vector<int> position;
    istringstream iss(s);
    string w;
    while(getline(iss, w, ',')) position.push_back(stoi(w));
    
    sort(position.begin(), position.end());
    int n = position.size();
    int l = 0, r = position[n-1] - position[0];
    int ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(possible(position, m, mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    out << ans << endl;
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
    bool possible(vector<int>& position, int m, int mid) {
        int n = position.size();
        int lastPos = position[0], balls = 1;
        for(int i=1; i<n; i++) {
            if(position[i] - lastPos >= mid) {
                balls++;   
                if(balls == m) return true;
                lastPos = position[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0, r = position[n-1] - position[0];
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(possible(position, m, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};