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