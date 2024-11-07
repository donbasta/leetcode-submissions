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
    bool isSubPath(ListNode* head, TreeNode* root) {
        function<bool(TreeNode*, ListNode*)> coba = [&](TreeNode* v, ListNode* w) -> bool {
            bool ret = false;
            if (w->next == nullptr) return true;
            if (v->left && v->left->val == w->next->val) {
                ret = ret || coba(v->left, w->next);
            }
            if (v->right && v->right->val == w->next->val) {
                ret = ret || coba(v->right, w->next);
            }
            return ret;
        };
        function<bool(TreeNode*)> dfs = [&](TreeNode* v) -> bool {
            bool ret = false;
            if (v->val == head->val) {
                ret = ret || coba(v, head);
            }
            if (v->left) ret = ret || dfs(v->left);
            if (v->right) ret = ret || dfs(v->right);
            return ret;
        };
        return dfs(root);
    }
};