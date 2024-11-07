class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int sum_col = accumulate(colsum.begin(), colsum.end(), 0);
        if (upper + lower != sum_col) return vector<vector<int>>();
        
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n));
        vector<int> cnt(3);
        vector<vector<int>> pos(3);
        for (int i = 0; i < n; i++) {
            cnt[colsum[i]]++;
            pos[colsum[i]].push_back(i);
        }

        if (lower < cnt[2]) return vector<vector<int>>();
        for (int i = 0; i < cnt[2]; i++) {
            ans[0][pos[2][i]] = ans[1][pos[2][i]] = 1;
        }
        for (int i = 0; i < lower - cnt[2]; i++) {
            ans[1][pos[1][i]] = 1;
        }
        for (int i = lower - cnt[2]; i < cnt[1]; i++) {
            ans[0][pos[1][i]] = 1;
        }
        return ans;
    }
};