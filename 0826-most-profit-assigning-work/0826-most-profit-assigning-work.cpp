#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& a, std::string& b, std::string& c) {
    a.erase(a.begin());
    a.pop_back();
    b.erase(b.begin());
    b.pop_back();
    c.erase(c.begin());
    c.pop_back();

    vector<int> worker;
    vector<pair<int, int>> vec;
    string w;
    int i = 0;

    istringstream issa(a);
    while(getline(issa, w, ',')) vec.push_back({stoi(w), 0});
    istringstream issb(b);
    while(getline(issb, w, ',')) vec[i++].second = stoi(w);
    istringstream issc(c);
    while(getline(issc, w, ',')) worker.push_back(stoi(w));

    int n = vec.size();
    int m = worker.size();

    sort(vec.begin(), vec.end());
    sort(worker.begin(), worker.end());

    int maxProfit = 0, bestProfit = 0, idx = 0;

    for(int i=0; i<m; i++) {
        while(idx < n && worker[i] >= vec[idx].first) {
            bestProfit = max(bestProfit, vec[idx].second);
            idx++;
        }
        maxProfit += bestProfit;
    }
    out << maxProfit << endl;
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string a, b, c;
    while (std::getline(std::cin, a) && std::getline(std::cin, b) && std::getline(std::cin, c)) {
        parse_input_and_solve(out, a, b, c);
    }
    out.flush();
    exit(0);
    return true;
}();




class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<vector<int>> vec(n);
        for(int i=0; i<n; i++) {
            vec[i] = {difficulty[i], profit[i]};
        }

        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, bestProfit = 0, idx = 0;

        for(int i=0; i<m; i++) {
            while(idx < n && worker[i] >= vec[idx][0]) {
                bestProfit = max(bestProfit, vec[idx][1]);
                idx++;
            }
            maxProfit += bestProfit;
        }
        return maxProfit;
    }
};