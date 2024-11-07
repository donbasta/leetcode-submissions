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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        int cnt = 1;
        ListNode* cur = head;
        ListNode* prv = nullptr;
        ListNode* bef = nullptr;
        ListNode* start_rev = nullptr;
        bool is_rev = false;
        while (cur) {
            if (cnt == left) {
                bef = prv;
                start_rev = cur;
                is_rev = true;
            }
            if (cnt == right) {
                if (bef) {
                    bef->next = cur;
                } else {
                    head = cur;
                }
                start_rev->next = cur->next;
                cur->next = prv;
                return head;
            }
            if (is_rev && cnt > left) {
                ListNode* tmp = cur->next;
                cur->next = prv;
                prv = cur;
                cur = tmp;
            } else {
                prv = cur;
                cur = cur->next;
            }
            cnt++;
        }
        return nullptr;
    }
};