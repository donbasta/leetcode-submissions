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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<pair<int, int>> tmp;
        int sz = 0;
        ListNode* l = head;
        while (l) {sz++, l = l->next;}
        vector<int> ret(sz);
        int idx = 0;
        while (head) {
            while (!tmp.empty() && head->val > tmp.back().second) {
                ret[tmp.back().first] = head->val;
                tmp.pop_back();
            }
            tmp.emplace_back(idx++, head->val);
            head = head->next;
        }
        return ret;
    }
};