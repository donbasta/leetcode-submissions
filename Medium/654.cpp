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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nullptr;
        int idx = -1, mx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                idx = i;
            }
        }
        TreeNode* ret = new TreeNode(mx);
        vector<int> le(nums.begin(), nums.begin() + idx);
        vector<int> ri(nums.begin() + idx + 1, nums.begin() + n);
        ret->left = constructMaximumBinaryTree(le);
        ret->right = constructMaximumBinaryTree(ri);
        return ret;
    }
};