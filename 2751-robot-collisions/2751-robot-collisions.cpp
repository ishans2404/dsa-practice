#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

using custom = pair<int, int>;

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t, std::string& dir) {
    s.erase(s.begin());
    s.pop_back();
    t.erase(t.begin());
    t.pop_back();
    dir.erase(dir.begin());
    dir.pop_back();
    
    vector<custom> robot;
    string w;
    int i = 0;
    istringstream iss(s);
    while(getline(iss, w, ',')) {
        robot.push_back({stoi(w), i++});
    }

    vector<int> heal(i);
    i = 0;
    istringstream ss(t);
    while(getline(ss, w, ',')) {
        heal[i++] = stoi(w);
    }

    sort(robot.begin(), robot.end(), greater<>());

    vector<int> st; // stack
    for(auto& [pos, i] : robot) {
        if(dir[i] == 'L') st.push_back(i);
        else {
            while(!st.empty() && heal[i] > 0) {
                int j = st.back();
                int x = heal[j] - heal[i];
                if(x > 0) {
                    heal[j]--;
                    heal[i] = 0;
                }
                else if(x < 0) {
                    heal[i]--;
                    heal[j] = 0;
                    st.pop_back();
                }
                else {
                    heal[j] = 0;
                    heal[i] = 0;
                    st.pop_back();
                }
            }
        }
    }
    w = "[";
    for(auto& i : heal) {
        if(i > 0) w += to_string(i) + ",";
    }
    if(w.back() == ',') w.pop_back();
    w += "]\n";
    out << w;
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string s, a, b;
    while (std::getline(std::cin, s) && std::getline(std::cin, a) && std::getline(std::cin, b)) {
        parse_input_and_solve(out, s, a, b);
    }
    out.flush();
    exit(0);
    return true;
}();



class Solution {
public:
    using int2=pair<int, int>;// (position, idx)
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        const int n=positions.size();
        vector<int2> robot(n);
        for(int i=0; i<n; i++)// 0-indexed is fine
            robot[i]={positions[i], i};
        sort(robot.begin(), robot.end(), greater<>());
        // for(auto& x:robot) cout<<x.first<<" "<<x.second<<"\n";

        vector<int> stack;
        for(auto& [pos, i]: robot){
            if (directions[i]=='L') stack.push_back(i);
            else{
                while(!stack.empty() && healths[i]>0){
                    int j=stack.back();
                    int x=healths[j]-healths[i];
                    if (x>0) healths[j]--, healths[i]=0;
                    else if (x<0) healths[j]=0, healths[i]--, stack.pop_back();
                    else healths[i]=healths[j]=0, stack.pop_back();
                }
            }
        }
        vector<int> ans;
        for(int x: healths)
            if (x>0) ans.push_back(x);
        return ans;
    }
};