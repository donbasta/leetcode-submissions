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
    int pairSum(ListNode* head) {
        vector<int> ve;
        while (head != nullptr) {
            ve.push_back(head->val);
            head = head->next;
        }
        int n = ve.size();
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, ve[i] + ve[n - 1 - i]);
        }
        return ans;
    }
};