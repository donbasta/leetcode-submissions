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
    void reorderList(ListNode* head) {
        vector<ListNode*> ve;
        while (head != NULL) {
            ve.emplace_back(head);
            head = head->next;
        }
        int n = ve.size();
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                if (i & 1) {
                    ve[n - 1 - (i / 2)]->next = NULL;
                } else {
                    ve[i / 2]->next = NULL;
                }
            } else {
                if (i & 1) {
                    assert(ve[n - 1 - (i / 2)] != NULL);
                    ve[n - 1 - (i / 2)]->next = ve[(i / 2) + 1];
                } else {
                    assert(ve[i / 2] != NULL);
                    ve[i / 2]->next = ve[n - 1 - (i / 2)];
                }
            }
        }
    }
};