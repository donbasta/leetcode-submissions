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
    TreeNode* recoverFromPreorder(string traversal) {
        const function<bool(char)> isDigit = [&](char c) -> bool {
            return (c >= '0') && (c <= '9');
        };
        vector<pair<int, int>> nodesDepth;
        // 1-2--3 -> {{1, 0}, {2, 1}, {3, 2}};
        int tmpDash = 0;
        string tmpNum;
        for (int i = 0; i < traversal.length(); i++) {
            if (traversal[i] == '-') {
                if (i > 0 && isDigit(traversal[i - 1])) {
                    nodesDepth.emplace_back(stoi(tmpNum), tmpDash);
                    tmpDash = 0;
                    tmpNum = "";
                }
                tmpDash++;
            }
            else if (isDigit(traversal[i])) {
                tmpNum.push_back(traversal[i]);
            }
        }
        nodesDepth.emplace_back(stoi(tmpNum), tmpDash);
        
        TreeNode* answer = new TreeNode(nodesDepth[0].first);
        vector<TreeNode*> ve(1000, NULL);
        ve[0] = answer;
        for (int i = 1; i < nodesDepth.size(); i++) {
            int newVal = nodesDepth[i].first;
            int newDepth = nodesDepth[i].second;
            TreeNode* par = ve[newDepth - 1];
            TreeNode* newNode = new TreeNode(newVal);
            if (par->left == NULL) {
                par->left = newNode;
            } else {
                par->right = newNode;
            }
            ve[newDepth] = newNode;
        }
        return answer;        
    }
};