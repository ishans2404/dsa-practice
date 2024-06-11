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
    vector<int> arr1, arr2;
    string word;
    
    istringstream iss1(s);
    while(getline(iss1, word, ',')) {
        arr1.push_back(stoi(word));
    }
    
    istringstream iss2(t);
    while(getline(iss2, word, ',')) {
        arr2.push_back(stoi(word));
    }
    
    vector<int> v(1001, 0);
    for(int i : arr1) v[i]++;
    arr1.clear();
    for(int i : arr2) {
        while(v[i] > 0) {
            arr1.push_back(i);
            v[i]--;
        }
    }
    for(int i=0; i<1001; i++) {
        if(v[i] > 0) {
            while(v[i] > 0) {
                arr1.push_back(i);
                v[i]--;
            }
        }
    }
    
    int n = arr1.size();
    out << "[";
    for(int i=0; i<n-1; i++) {
        out << arr1[i] << ",";
    }
    out << arr1[n-1] << "]\n";
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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v(1001, 0);
        for(int i : arr1) v[i]++;
        arr1.clear();
        for(int i : arr2) {
            while(v[i] > 0) {
                arr1.push_back(i);
                v[i]--;
            }
        }
        for(int i=0; i<1001; i++) {
            if(v[i] > 0) {
                while(v[i] > 0) {
                    arr1.push_back(i);
                    v[i]--;
                }
            }
        }
        return arr1;
    }
};