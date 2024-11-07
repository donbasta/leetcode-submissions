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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* cur = head;
        int len = 0;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }
        if (len == 0) return head;
        k %= len;
        cur = head;
        for (int i = 0; i < k; i++) {
            cur = cur->next;
        }
        ListNode* cur2 = head;
        while (cur->next != nullptr) {
            cur = cur->next;
            cur2 = cur2->next;
        }
        cur->next = head;
        ListNode* ret = cur2->next;
        cur2->next = nullptr;
        return ret;
    }
};