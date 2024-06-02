#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();

inline bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

void parse_input_and_solve(std::ofstream& out, std::string& s) {
    const int N = s.size()-1;
    string ans = "";
    string temp = "";
    int j = 1;
    for(int i=1; i<N; i++) {
        if(i == N-1 && s[i] != ' ') {
            temp += s[i];
            int k = temp.length()-1;
            while(k >= 0) s[j++] = temp[k--];
            s[j++] = ' ';
            temp = "";
        }
        else if(s[i] == ' ' && (s[i-1] == '"' || s[i-1] == ' ')) continue;
        else if(s[i] == ' ' && s[i-1] != ' ') {
            int k = temp.length()-1;
            while(k >= 0) s[j++] = temp[k--];
            s[j++] = ' ';
            temp = "";
        }
        else temp += s[i];
    }
    cout<<j<<" "<<s[j]<<endl;
    int i = N;
    while(i != j-2) {
        i--;
        s.pop_back();
    }
    s += '"';
    reverse(s.begin(), s.end());
    out << s << endl;
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
    string reverseWords(string s) {
        return s;
    }
};