#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t, std::string& c) {
    s.erase(s.begin());
    s.pop_back();
    t.erase(t.begin());
    t.pop_back();
    int min = stoi(c);
    vector<int> cust, grum;
    istringstream iss1(s);
    istringstream iss2(t);
    string w;
    while(getline(iss1, w, ',')) cust.push_back(stoi(w));
    while(getline(iss2, w, ',')) grum.push_back(stoi(w));
    
    int n = cust.size();
    int gain = 0;
    int loss = 0;
    for(int i=0; i<n; i++) {
        if(grum[i] == 0) gain += cust[i];
    }

    for(int i=0; i<min; i++) {
        if(grum[i] == 1) loss += cust[i];
    }

    int total = loss;

    for(int i=min; i<n; i++) {
        if(grum[i-min] == 1) loss -= cust[i-min]; // remove last element of window
        if(grum[i] == 1) loss += cust[i];  // add new element to window
        total = max(total, loss);  // maximise total
    }
    out << gain + total << endl;
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string s, t, c;
    while (std::getline(std::cin, s) && std::getline(std::cin, t) && std::getline(std::cin, c)) {
        parse_input_and_solve(out, s, t, c);
    }
    out.flush();
    exit(0);
    return true;
}();




class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grum, int min) {
        int n = cust.size();
        int gain = 0;
        int loss = 0;
        for(int i=0; i<n; i++) {
            if(grum[i] == 0) gain += cust[i];
        }

        for(int i=0; i<min; i++) {
            if(grum[i] == 1) loss += cust[i];
        }

        int total = loss;

        for(int i=min; i<n; i++) {
            if(grum[i-min] == 1) loss -= cust[i-min]; // remove last element of window
            if(grum[i] == 1) loss += cust[i];  // add new element to window
            total = max(total, loss);  // maximise total
        }
        return gain + total;
    }
};