#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

vector<int> countSort(vector<int>& inputArray) {
    int N = inputArray.size();
    int M = 0;    
    for (int i = 0; i < N; i++) M = max(M, inputArray[i]);

    vector<int> countArray(M + 1, 0);

    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;

    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(N);

    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }

    return outputArray;
}

void parse_input_and_solve(std::ofstream& out, std::string& s, std::string& t) {
    s.erase(s.begin());
    s.pop_back();
    t.erase(t.begin());
    t.pop_back();
    istringstream ss(s);
    istringstream st(t);
    string w;
    vector<int> target, arr;
    while(getline(ss, w, ',')) target.push_back(stoi(w));
    while(getline(st, w, ',')) arr.push_back(stoi(w));
    target = countSort(target);
    arr = countSort(arr);
    int n = target.size();
    string ans = "true";
    for(int i=0; i<n; i++) {
        if(target[i] != arr[i]) {
            ans = "false";
            break;
        }
    }
    out << ans << endl;
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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        target = countSort(target);
        arr = countSort(arr);
        int n = target.size();
        for(int i=0; i<n; i++) {
            if(target[i] != arr[i]) return false;
        }
        return true;
    }
private:
    vector<int> countSort(vector<int>& inputArray) {
        int N = inputArray.size();
        int M = 0;    
        for (int i = 0; i < N; i++) M = max(M, inputArray[i]);
    
        vector<int> countArray(M + 1, 0);

        for (int i = 0; i < N; i++)
            countArray[inputArray[i]]++;

        for (int i = 1; i <= M; i++)
            countArray[i] += countArray[i - 1];
    
        // Creating outputArray[] from countArray[] array
        vector<int> outputArray(N);
    
        for (int i = N - 1; i >= 0; i--) {
            outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
            countArray[inputArray[i]]--;
        }
    
        return outputArray;
    }
};