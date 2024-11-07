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
class FindElements {
public:
    set<int> values;

    FindElements(TreeNode* root) {
        const function<void(TreeNode*, int)> dfs = [&](TreeNode* v, int val) -> void {
            values.emplace(val);
            if (v->left) dfs(v->left, 2 * val + 1);
            if (v->right) dfs(v->right, 2 * val + 2);
        };
        dfs(root, 0);
    }
    
    bool find(int target) {
        return values.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */