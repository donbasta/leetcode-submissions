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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> ve;
        while (head != nullptr) {
            ve.emplace_back(head);
            head = head->next;
        }
        int n = ve.size();
        int tmp = ve[k - 1]->val;
        ve[k - 1]->val = ve[n - k]->val;
        ve[n - k]->val = tmp;
        return ve[0];
    }
};