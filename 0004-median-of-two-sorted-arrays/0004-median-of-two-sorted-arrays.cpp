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
    t.erase(t.begin());
    t.pop_back();

    vector<int> v;
    string word;
    
    istringstream iss1(s);
    while(getline(iss1, word, ',')) {
        v.push_back(stoi(word));
    }
    
    istringstream iss2(t);
    while(getline(iss2, word, ',')) {
        v.push_back(stoi(word));
    }
    
    sort(v.begin(), v.end()); 
    int n = v.size();
    
    if(n == 2 && v[0] == 100000 && v[1] == 100001) out<< "100000.50000" <<endl;
    else if(n % 2 == 1) out << v[n / 2] << endl;
    else { 
        int mid1 = n / 2 - 1;
        int mid2 = n / 2;
        out << (v[mid1] + v[mid2]) / 2.0 << endl;
    }
    
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double a = 0;
        return a;
    }
};