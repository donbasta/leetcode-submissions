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
    ListNode* middleNode(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while (true) {
            hare = hare->next;
            if (!hare) return tortoise;
            hare = hare->next;
            if (!hare) return tortoise->next;
            tortoise = tortoise->next;
        }
        return nullptr;
    }
};