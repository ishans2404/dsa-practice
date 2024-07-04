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
        vector<int> v;
        ListNode* curr = head->next;
        int sum = 0;
        while(curr) {
            if(curr->val == 0) {
                v.push_back(sum);
                sum = 0;
            }
            else sum += curr->val;
            curr = curr->next;
        }
        sum = v.size();
        int i = 0;
        curr = head;
        while(i < sum-1) {
            curr->val = v[i++];
            curr = curr->next;
        }
        curr->val = v[i];
        ListNode* temp = curr->next;
        
        while(temp) {
            ListNode* prev = temp;
            temp = temp->next;
            delete prev;
        }
        curr->next = nullptr;
        return head;
    }
};