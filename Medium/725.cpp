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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            sz++;
        }
        int each = sz / k;
        int more = sz % k;
        vector<ListNode*> ret;
        cur = head;
        int tmp = 0;
        ListNode* lmao = nullptr;
        for (int i = 0; i < k; i++) {
            lmao = nullptr;
            for (int j = 0; j < each; j++) {
                if (lmao == nullptr) {
                    lmao = cur;
                } else {
                    cur = cur->next;
                }
            }
            if (i < more) {
                if (lmao == nullptr) {
                    lmao = cur;
                } else {
                    cur = cur->next;
                }
            }
            if (cur) {
                ListNode* last = cur;
                cur = cur->next;
                last->next = nullptr;
            }
            ret.push_back(lmao);
        }
        return ret;
    }
};