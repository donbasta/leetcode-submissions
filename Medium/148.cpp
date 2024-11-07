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
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head;
        vector<int> ve;
        while (cur) {
            ve.push_back(cur->val);
            cur = cur->next;
        }
        sort(ve.begin(), ve.end());
        ListNode* ret = new ListNode(ve[0]);
        cur = ret;
        for (int i = 1; i < ve.size(); i++) {
            cur->next = new ListNode(ve[i]);
            cur = cur->next;
        }
        return ret;
    }
};