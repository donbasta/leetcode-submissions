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

    ListNode* reverse(ListNode* head, int k) {
        vector<ListNode*> ve;
        for (int i = 0; i < k; i++) {
            ve.emplace_back(head);
            head = head->next;
        }
        for (int i = k - 1; i >= 1; i--) {
            ve[i]->next = ve[i - 1];
        }
        return ve[k - 1];
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            if (cur == nullptr) return head;
            cur = cur->next;
        }
        ListNode* bruh = reverse(head, k);
        head->next = reverseKGroup(cur, k);
        return bruh;
    }
};