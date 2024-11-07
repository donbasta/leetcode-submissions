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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = NULL;
        ListNode* right = NULL;
        ListNode* startLeft = NULL;
        ListNode* startRight = NULL;
        bool l = false, r = false;
        while (head != NULL) {
            if (head->val < x) {
                if (!l) {
                    startLeft = new ListNode(head->val);
                    left = startLeft;
                    l = true;
                } else {
                    left->next = new ListNode(head->val);
                    left = left->next;
                }
            } else if (head->val >= x) {
                if (!r) {
                    startRight = new ListNode(head->val);
                    right = startRight;
                    r = true;
                } else {
                    right->next = new ListNode(head->val);
                    right = right->next;
                }
            }
            head = head->next;
        }
        if (!l) {
            return startRight;
        }
        left->next = startRight;
        return startLeft;
    }
};