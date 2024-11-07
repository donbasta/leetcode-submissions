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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> ve;
        while (head) {
            ve.emplace_back(head->val);
            head = head->next;
        }
        const function<TreeNode*(int, int)> f = [&](int l, int r) -> TreeNode* {
            if (r < l) return nullptr;
            int mid = (l + r) >> 1;
            TreeNode* ret = new TreeNode(ve[mid]);
            ret->left = f(l, mid - 1);
            ret->right = f(mid + 1, r);
            return ret;
        }; 
        return f(0, (int) ve.size() - 1);
    }
};