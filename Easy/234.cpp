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
    bool isPalindrome(ListNode* head) {
        vector<int> ve;
        while (head != nullptr) {
            ve.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < ve.size(); i++) {
            if (ve[i] != ve[ve.size() - 1 - i]) return false;
        }
        return true;
    }
};