// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// static const bool Booster = [](){
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return true;
// }();


// void parse_input_and_solve(std::ofstream& out, std::string& s) {
//     s.erase(s.begin());
//     s.pop_back();
    
//     string w;
//     int i;
//     vector<int> nums;
//     int freq[201] = {0};
//     istringstream iss(s);
//     while(getline(iss, w, ',')) {
//         i = stoi(w);
//         nums.push_back(i);
//         freq[i+100]++;
//     }
    
//     sort(nums.begin(), nums.end(), [&](int& x, int& y) {
//         return (freq[x+100] == freq[y+100]) ? x>y : freq[x+100] < freq[y+100];
//     });
    
//     out << "[";
//     i = nums.size() - 1;
//     for(int j=0; j<i; j++) out << nums[j] << ",";
//     out << nums[i] << "]\n";
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
    vector<int> frequencySort(vector<int>& nums) {
        // std::ios_base::sync_with_stdio(false);
        // std::cin.tie(nullptr);
        // std::cout.tie(nullptr);
        
        int freq[201] = {0};
        for(int& i:nums) freq[i+100]++;

        sort(nums.begin(), nums.end(), [&](int& x, int& y) {
            return (freq[x+100] == freq[y+100]) ? x>y : freq[x+100] < freq[y+100];
        });

        return nums;
    }
};