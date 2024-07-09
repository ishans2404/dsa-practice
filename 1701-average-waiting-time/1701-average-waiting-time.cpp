// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// static const bool Booster = [](){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return true;
// }();

// void parse_input_and_solve(std::ofstream& out, const std::string& s) {
//     string t = "", w;
//     for(char ch : s) {
//         if(ch == '[' || ch == ']') continue;
//         else t += ch;
//     }
//     istringstream iss(t);
//     vector<vector<int>> c;
//     vector<int> temp;
//     int a = 0, b = 0;
//     while(getline(iss, w, ',')) {
//         temp.push_back(stoi(w));
//         if(temp.size() == 2) {
//             c.push_back(temp);
//             temp.clear();
//         }
//     }
    
//     int currTime = 0;
//     long long totalWait = 0;

//     for(auto v : c) {
//         int arr = v[0];
//         int time = v[1];

//         if(currTime < arr) currTime = arr;
//         int wait = currTime + time - arr;

//         totalWait += wait;
//         currTime += time;
//     }
//     out << static_cast<double>(totalWait) / c.size() << endl;
// }

// bool Solve = [](){
//     std::ofstream out("user.out");
//     for (std::string s; std::getline(std::cin, s);) {
//         parse_input_and_solve(out, s);
//     }
//     out.flush();
//     exit(0);
//     return true;
// }();


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        int currTime = 0;
        long long totalWait = 0;

        for(auto v : c) {
            int arr = v[0];
            int time = v[1];

            if(currTime < arr) currTime = arr;
            int wait = currTime + time - arr;

            totalWait += wait;
            currTime += time;
        }
        return static_cast<double>(totalWait) / n;
    }
};