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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = nullptr;
        ListNode* cur = nullptr;
        int carry = 0;
        while (l1 || l2) { 
            int a1 = (l1 ? l1->val : 0);
            int b1 = (l2 ? l2->val : 0);
            int sum = carry + a1 + b1;
            int dig = (sum % 10);
            carry = (sum / 10);
            if (ret) {
                cur->next = new ListNode(dig);
                cur = cur->next;
            } else {
                ret = cur = new ListNode(dig);
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) {
            assert(carry == 1);
            cur->next = new ListNode(carry);
        }
        return ret;
    }
};