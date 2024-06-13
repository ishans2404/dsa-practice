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
    
    vector<int> v1, v2;
    string w;
    
    istringstream iss1(s);
    while(getline(iss1, w, ',')) v1.push_back(stoi(w));
    
    istringstream iss2(t);
    while(getline(iss2, w, ',')) v2.push_back(stoi(w));
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    int c = 0, n = v1.size();
    for(int i=0; i<n; i++) c += abs(v1[i] - v2[i]);
    
    out << c << endl;
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
    vector<int> countSort(vector<int>& inputArray) {
        int N = inputArray.size();
        int M = *max_element(inputArray.begin(), inputArray.end());

        vector<int> countArray(M + 1, 0);
        for (int i = 0; i < N; i++) countArray[inputArray[i]]++;
        for (int i = 1; i <= M; i++) countArray[i] += countArray[i - 1];

        vector<int> outputArray(N);
        for (int i = N - 1; i >= 0; i--) {
            outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
            countArray[inputArray[i]]--;
        }
        return outputArray;
    }

    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        seats = countSort(seats);
        students = countSort(students);
        int c = 0, n = seats.size();
        for(int i=0; i<n; i++) c += abs(seats[i] - students[i]);
        return c;
    }
};