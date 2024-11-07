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
    ListNode* doubleIt(ListNode* head) {
        vector<int> digits;
        while (head) {
            digits.push_back(head->val);
            head = head->next;
        }
        vector<int> dbl;
        int carry = 0;
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            int tot = digits[i] * 2 + carry;
            dbl.push_back(tot % 10);
            carry = tot / 10;
        }
        if (carry > 0) dbl.push_back(carry);
        reverse(dbl.begin(), dbl.end());
        ListNode* ret = new ListNode(dbl[0]);
        ListNode* cur = ret;
        for (int i = 1; i < dbl.size(); i++) {
            ListNode* tmp = new ListNode(dbl[i]);
            cur->next = tmp;
            cur = tmp;
        }
        return ret;
    }
};