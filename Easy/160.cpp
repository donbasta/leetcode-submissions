/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        ListNode* lastA = NULL;
        ListNode* lastB = NULL;
        if(cur1 == NULL || cur2 == NULL)
            return NULL;
        while(cur1 != cur2) {
            if(cur1->next == NULL) {
                lastA = cur1;
            }
            cur1 = cur1->next == NULL ? headB : cur1->next;
            if(cur2->next == NULL) {
                lastB = cur2;
            }
            cur2 = cur2->next == NULL ? headA : cur2->next;
            if(lastA != NULL && lastB != NULL && lastA != lastB) {
                return NULL;
            }
        }
        return cur1;
    }
};