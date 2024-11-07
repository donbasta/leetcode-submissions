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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ve(m, vector<int>(n, -1));
        pair<int, int> dir[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cur_i = 0, cur_j = 0;
        int cur_dir = 0;
        while (head) {
            ve[cur_i][cur_j] = head->val;
            head = head->next;
            int n_cur_i = cur_i + dir[cur_dir].first, n_cur_j = cur_j + dir[cur_dir].second;
            if (n_cur_i < 0 || n_cur_i >= m || n_cur_j < 0 || n_cur_j >= n || ve[n_cur_i][n_cur_j] != -1) {
                cur_dir = (cur_dir + 1) % 4;
                n_cur_i = cur_i + dir[cur_dir].first, n_cur_j = cur_j + dir[cur_dir].second;
            }
            cur_i = n_cur_i, cur_j = n_cur_j;
        }
        return ve;
    }
};