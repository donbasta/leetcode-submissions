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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* cur = head;
        while (cur) {
            sz++, cur = cur->next;
        }
        if (n == sz) {
            return head->next;
        }
        ListNode* prv = nullptr;
        cur = head;
        int tmp = 0;
        while (cur) {
            tmp++;
            if (tmp == sz - n + 1) {
                prv->next = cur->next;
                break;
            }
            prv = cur;
            cur = cur->next;
        }
        return head;
    }
};