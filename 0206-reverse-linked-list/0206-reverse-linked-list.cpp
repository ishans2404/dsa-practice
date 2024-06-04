#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return true;
}();


void parse_input_and_solve(std::ofstream& out, std::string& s) {
    if(s.size() == 2) {
        out << s << endl;
        return;
    }
    s.erase(s.begin());
    s.pop_back();
    vector<string> res;
    istringstream iss(s);
    string word;
    while (getline(iss, word, ',')) res.push_back(word);
    out << "[";
    int n = res.size();
    for(int i=n-1; i>=1; i--) out<<res[i]<<",";
    out<<res[0]<<"]\n";
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




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* ahead = nullptr;
        while(curr) {
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        head = prev;
        return head;
    }
};