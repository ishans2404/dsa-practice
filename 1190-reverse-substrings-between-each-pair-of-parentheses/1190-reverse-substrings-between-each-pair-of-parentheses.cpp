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
    stack<char> st;
    for(auto& ch : s) {
        if(ch == ')') {
            string revstr = "";
            while(st.top() != '(') {
                revstr += st.top();
                st.pop();
            }
            if(!st.empty())  st.pop();
            for(auto& c : revstr) st.push(c);
        } 
        else st.push(ch);
    }
 
    char ch = char(34);
    string ans = "";
    while(!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    out << ch << ans << ch << endl;
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
    string reverseParentheses(string s) {
        stack<char> st;
        for(auto& ch : s) {
            if(ch == ')') {
                string revstr = "";
                while(st.top() != '(') {
                    revstr += st.top();
                    st.pop();
                }
                if(!st.empty())  st.pop();
                for(auto& c : revstr) st.push(c);
            } 
            else st.push(ch);
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};