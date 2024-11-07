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
        if (!head->next) return nullptr;
        ListNode* p = head;
        ListNode* q = head;
        ListNode* prv;
        while (q && q->next) {
            prv = p;
            p = p->next;
            q = q->next;
            if (q) {
                q = q->next;
            }
        }
        if (!prv) return head->next;
        prv->next = p->next;
        return head;
    }
};