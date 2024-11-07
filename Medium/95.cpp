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
    vector<TreeNode*> generateTrees(int n) {
        const function<vector<TreeNode*>(int, int)> rec = [&](int a, int b) -> vector<TreeNode*> {
            vector<TreeNode*> ret;
            if (a > b) return ret;
            for (int i = a; i <= b; i++) {
                vector<TreeNode*> L = rec(a, i - 1);
                vector<TreeNode*> R = rec(i + 1, b);
                if (L.empty()) L.push_back(nullptr);
                if (R.empty()) R.push_back(nullptr);
                for (int j = 0; j < L.size(); j++) {
                    for (int k = 0; k < R.size(); k++) {
                        TreeNode* root = new TreeNode(i);
                        root->left = L[j];
                        root->right = R[k];
                        ret.push_back(root);
                    }
                }
            }
            return ret;
        }; 
        return rec(1, n);
    }
};