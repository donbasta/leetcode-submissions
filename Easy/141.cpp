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
    bool hasCycle(ListNode *head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        if (!head) return false;
        while (true) {
            tortoise = tortoise->next;
            hare = hare->next;
            if (!hare) return false;
            hare = hare->next;
            if (!hare) return false;
            if (tortoise == hare) return true;
        }
        return false;
    }
};