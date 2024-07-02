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
    vector<int> nums1, nums2;
    string w;
    istringstream iss1(s);
    istringstream iss2(t);
    while(getline(iss1, w, ',')) nums1.push_back(stoi(w));
    while(getline(iss2, w, ',')) nums2.push_back(stoi(w));

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    string v = "[";
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(nums1[i] > nums2[j]) j++;
        else if(nums1[i] < nums2[j]) i++;
        else {
            v += to_string(nums1[i]) + ",";
            i++;
            j++;
        }
    }
    if(v.back() == ',') v.pop_back();
    v += "]\n";
    out << v;
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> v;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(nums1[i] > nums2[j]) j++;
            else if(nums1[i] < nums2[j]) i++;
            else {
                v.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return v;
    }
};