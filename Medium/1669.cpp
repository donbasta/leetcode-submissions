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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int idx = 0;
        ListNode* cur = list1;
        ListNode* le = nullptr;
        ListNode* ri = nullptr;
        while (cur) {
            if (idx == a - 1) {
                le = cur;
            }
            if (idx == b + 1) {
                ri = cur;
                break;
            }
            idx++;
            cur = cur->next;
        }
        le->next = list2;
        cur = list2;
        while (cur->next) cur = cur->next;
        cur->next = ri;
        return list1;
    }
};