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