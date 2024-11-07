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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        const int INF = 2e9;
        int tot = 0, mn = INF;
        int prv_idx = -1;
        ListNode* prv = head;
        ListNode* cur = head->next;
        int idx = 1;
        while (cur->next) {
            int a = prv->val;
            int b = cur->val;
            int c = cur->next->val;
            if (1ll * (b - a) * (b - c) > 0ll) {
                if (prv_idx != -1) {
                    mn = min(mn, idx - prv_idx);
                    tot += idx - prv_idx;
                }
                prv_idx = idx;
            }
            idx++;
            prv = cur;
            cur = cur->next;
        } 
        if (mn == INF) return vector<int>{-1, -1};
        return vector<int>{mn, tot};
    }
};