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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int, bool> ada;
        for (auto e : nums) ada[e] = true;
        int comp = 0;
        bool cool = false;
        while (head) {
            if (ada[head->val]) {
                if (!cool) {
                    cool = true;
                    comp++;
                }
            } else {
                cool = false;
            }
            head = head->next;
        }
        return comp;
    }
};