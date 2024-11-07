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
        vector<int> v1, v2;
        ListNode* ptr = l1;
        while (ptr) {
            v1.push_back(ptr->val);
            ptr = ptr->next;
        }
        ptr = l2;
        while (ptr) {
            v2.push_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        vector<int> res;
        int carry = 0;
        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int lmao = carry;
            if (i < v1.size()) lmao += v1[i];
            if (i < v2.size()) lmao += v2[i];
            res.push_back(lmao % 10);
            carry = lmao / 10;
        }
        if (carry > 0) res.push_back(carry);
        reverse(res.begin(), res.end());
        ListNode* ret = new ListNode(res[0]);
        ptr = ret;
        for (int i = 1; i < res.size(); i++) {
            ptr->next = new ListNode(res[i]);
            ptr = ptr->next;
        }
        return ret;
    }
};