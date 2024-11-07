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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        if (!cur) return head;
        ListNode* nx = cur->next;
        while (nx) {
            if (nx->val == cur->val) {
                nx = nx->next;
            } else {
                cur->next = nx;
                cur = nx;
                nx = nx->next;
            }
        }
        cur->next = nx;
        return head;
    }
};