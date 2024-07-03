#include <algorithm>

template<typename T>
T min(T a, T b, T c, T d, T e) {
    return min(min(min(min(a, b), c), d), e);
}

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

    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
    istringstream iss(s);
    string w;
    int i, val;

    int comma = 0;
    for(auto c : s) {
        if(c == ',') comma++;
        if(comma >= 4) {
            goto label;
        }
    }
    if(comma < 4) {
        out << "0\n";
        goto endLabel;
    }
    label:
    
    
    while(getline(iss, w, ',')) {
        i = stoi(w);
        if(i < min1) {
            min4 = min3;
            min3 = min2;
            min2 = min1;
            min1 = i;
        } 
        else if(i < min2) {
            min4 = min3;
            min3 = min2;
            min2 = i;
        } 
        else if(i < min3) {
            min4 = min3;
            min3 = i;
        }
        else if(i < min4) {
            min4 = i;
        }

        if(i > max1) {
            max4 = max3;
            max3 = max2;
            max2 = max1;
            max1 = i;
        } 
        else if(i > max2) {
            max4 = max3;
            max3 = max2;
            max2 = i;
        } 
        else if(i > max3) {
            max4 = max3;
            max3 = i;
        }
        else if(i > max4) {
            max4 = i;
        }
    }
    
    val = INT_MAX;
    val = min(val, max4 - min1, max1 - min4, max2 - min3, max3 - min2);  
    // remove last 3, remove first 3, remove first 2 last 1, remove first 1 last 2
    out << val << endl;
    
    endLabel:
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
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        if(n <= 4) return 0;
        
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
        
        for(int i : arr) {
            if(i < min1) {
                min4 = min3;
                min3 = min2;
                min2 = min1;
                min1 = i;
            } 
            else if(i < min2) {
                min4 = min3;
                min3 = min2;
                min2 = i;
            } 
            else if(i < min3) {
                min4 = min3;
                min3 = i;
            }
            else if(i < min4) {
                min4 = i;
            }
            
            if(i > max1) {
                max4 = max3;
                max3 = max2;
                max2 = max1;
                max1 = i;
            } 
            else if(i > max2) {
                max4 = max3;
                max3 = max2;
                max2 = i;
            } 
            else if(i > max3) {
                max4 = max3;
                max3 = i;
            }
            else if(i > max4) {
                max4 = i;
            }
        }

        int val = INT_MAX;
        val = min(val, max4 - min1, max1 - min4, max2 - min3, max3 - min2);  
        // remove last 3, remove first 3, remove first 2 last 1, remove first 1 last 2
        return val;
    }
};