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
    string w;
    istringstream iss(s);
    vector<int> nums;
    while(getline(iss, w, ',')) nums.push_back(stoi(w));
    
    int prev = 0, curr = 1, nxt = 2;

    int minDist = INT_MAX, maxDist = INT_MIN;
    int firstCritical = -1, lastCritical = -1, prevCritical = -1;
    int pos = 1;

    string res;
    int n = nums.size();
    if(n < 3) {
        out << "[-1,-1]\n";
        goto lab;
    }

    while(nxt < n) {
        if((nums[curr] > nums[prev] && nums[curr] > nums[nxt]) ||
        (nums[curr] < nums[prev] && nums[curr] < nums[nxt])) {
            if(firstCritical == -1) firstCritical = pos;
            else minDist = min(minDist, pos - prevCritical);
            prevCritical = pos;
            lastCritical = pos;
        }
        prev = curr;
        curr = nxt;
        nxt++;
        pos++;            
    }
    if(firstCritical == lastCritical) {
        out << "[-1,-1]\n";
        goto lab;
    }

    maxDist = lastCritical - firstCritical;
    res = "[" + to_string(minDist) + "," + to_string(maxDist) + "]\n";
    out << res;
    lab:
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;
        head = head->next;

        int minDist = INT_MAX, maxDist = INT_MIN;
        int firstCritical = -1, lastCritical = -1, prevCritical = -1;
        int pos = 1;

        while(nxt) {
            if((curr->val > prev->val && curr->val > nxt->val) ||
            (curr->val < prev->val && curr->val < nxt->val)) {
                if(firstCritical == -1) firstCritical = pos;
                else minDist = min(minDist, pos - prevCritical);
                prevCritical = pos;
                lastCritical = pos;
            }
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            pos++;            
        }
        if(firstCritical == lastCritical) return {-1, -1};

        maxDist = lastCritical - firstCritical;
        return {minDist, maxDist};
    }
};