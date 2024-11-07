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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> se;
        for (auto e : nums) se.insert(e);
        ListNode* ans = nullptr;
        ListNode* last = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (se.count(cur->val)) {
                //do nothing
            } else {
                if (last != nullptr) {
                    last->next = cur;
                    last = cur;
                } else {
                    ans = cur;
                    last = cur;
                }
            }
            cur = cur->next;
        }
        if (last != nullptr) last->next = nullptr;
        return ans;
    }
};