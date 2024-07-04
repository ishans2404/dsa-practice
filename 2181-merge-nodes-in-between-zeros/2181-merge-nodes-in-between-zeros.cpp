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
    s.erase(s.begin());
    s.erase(s.begin());
    s.pop_back();
    string w;
    istringstream iss(s);
    int sum = 0;

    string t = "[";
    while(getline(iss, w, ',')) {
        int val = stoi(w);
        if(val == 0) {
            t += to_string(sum) + ",";
            sum = 0;
        }
        else sum += val;
    }
    t.pop_back();
    t += "]\n";
    out << t;
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* curr = head->next;
        int sum = 0;
        while(curr) {
            if(curr->val == 0) {
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            }
            else sum += curr->val;
            curr = curr->next;
        }
        return dummy.next;
    }
};