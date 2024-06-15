#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

void parse_input_and_solve(std::ofstream& out, std::string& a, std::string& b, std::string& c, std::string& d) {
    int k = stoi(a), w = stoi(b);
    c.erase(c.begin());
    c.pop_back();
    d.erase(d.begin());
    d.pop_back();
    vector<int> capital, profits;
    string wrd;
    istringstream iss1(c);
    while(getline(iss1, wrd, ',')) {
        profits.push_back(stoi(wrd));
    }
    istringstream iss2(d);
    while(getline(iss2, wrd, ',')) {
        capital.push_back(stoi(wrd));
    }
    vector<pair<int,int>> vec;
    for(int i=0; i<profits.size(); i++){
        vec.push_back({profits[i],capital[i]});
    }
    auto comp = [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    };
    sort(vec.begin(),vec.end(),comp);
    priority_queue<int> pq;
    int j=0;
    while(j<profits.size() && vec[j].second <= w){
        pq.push(vec[j].first);
        j++;
    }
    while(!pq.empty() && k > 0){
        w += pq.top();
        pq.pop();
        while(j<profits.size() && vec[j].second <= w){
            pq.push(vec[j].first);
            j++;
        }
        k--;
    }
    out<<w<<endl;
    
}

bool Solve = []() {
    std::ofstream out("user.out");
    std::string a, b, c, d;
    while (std::getline(std::cin, a) && std::getline(std::cin, b) && std::getline(std::cin, c) && std::getline(std::cin, d)) {
        parse_input_and_solve(out, a, b, c, d);
    }
    out.flush();
    exit(0);
    return true;
}();



class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> vec;
        for(int i=0; i<profits.size(); i++){
            vec.push_back({profits[i],capital[i]});
        }
        auto comp = [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        };
        sort(vec.begin(),vec.end(),comp);
        priority_queue<int> pq;
        int j=0;
        while(j<profits.size() && vec[j].second <= w){
            pq.push(vec[j].first);
            j++;
        }
        while(!pq.empty() && k > 0){
            w += pq.top();
            pq.pop();
            while(j<profits.size() && vec[j].second <= w){
                pq.push(vec[j].first);
                j++;
            }
            k--;
        }
        return w;
    }
};