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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ans = nullptr;
        ListNode* ptrAns = nullptr;
        ptr = head->next;
        bool found = false;
        while (ptr != nullptr) {
            int sum = 0;
            while (ptr->val != 0) {
                sum += ptr->val;
                ptr = ptr->next;
            }
            ptr = ptr->next;
            ListNode* newNode = new ListNode(sum);
            if (!found) {
                ans = newNode;
                ptrAns = newNode;
                found = true;
            } else {
                ptrAns->next = newNode;
                ptrAns = ptrAns->next;
            }
        }
        return ans;
    }
};