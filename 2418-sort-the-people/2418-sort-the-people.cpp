class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int num = h.size();
        map<int, string> m;

        for(int i=0; i<num; i++) {
            m[h[i]] = n[i];
        }

        num--;
        for(auto& it:m) {
            n[num--] = it.second;
        }

        return n;
    }
};