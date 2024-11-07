/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* cur = head;
        unordered_map<ListNode*, bool> vis;
        while (cur != nullptr) {
            if (vis.find(cur) != vis.end()) {
                return cur;
            }
            vis[cur] = true;
            cur = cur->next;
        }
        return nullptr;
    }
};