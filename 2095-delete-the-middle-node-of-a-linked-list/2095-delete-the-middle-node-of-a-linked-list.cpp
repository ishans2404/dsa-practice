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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0, i = 0;
        ListNode* it = head;
        while(it) {
            n++;
            it = it->next;
        }
        if(n == 1) return nullptr;
        it = head;
        while(i < n/2-1) {
            i++;
            it = it->next;
        }
        ListNode* current = it->next;
        ListNode* ahead = current->next;
        if(!ahead) it->next = nullptr;
        else it->next = ahead;
        return head;
    }
};