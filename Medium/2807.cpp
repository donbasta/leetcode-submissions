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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ret = head;
        while (head) {
            ListNode* nx = head->next;
            if (nx) {
                int gcd = __gcd(head->val, nx->val);
                ListNode* gcd_node = new ListNode(gcd);
                head->next = gcd_node;
                gcd_node->next = nx;
            }
            head = nx;
        }
        return ret;
    }
};