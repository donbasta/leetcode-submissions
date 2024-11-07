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
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        if (head->next->val != head->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        ListNode* bruh = head;
        while (bruh != nullptr && bruh->val == head->val) {
            bruh = bruh->next;
        }
        return deleteDuplicates(bruh);
    }
};