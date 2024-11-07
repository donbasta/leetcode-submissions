class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int ve[n];
        for (int i = 0; i < n; i++) ve[i] = i;
        vector<vector<string>> ans;
        do {
            int c1[2 * n], c2[2 * n];
            for (int i = 0; i < 2 * n; i++) c1[i] = c2[i] = 0;
            for (int i = 0; i < n; i++) {
                c1[i - ve[i] + (n - 1)]++, c2[i + ve[i]]++;
            }
            bool can = true;
            for (int i = 0; i < 2 * n; i++) {
                if (c1[i] > 1) can = false;
            }
            for (int i = 0; i < 2 * n; i++) {
                if (c2[i] > 1) can = false;
            }
            if (can) {
                vector<string> tmp;
                for (int i = 0; i < n; i++) {
                    string lol(n, '.');
                    lol[ve[i]] = 'Q';
                    tmp.push_back(lol);
                }
                ans.push_back(tmp);
            }
        } while (next_permutation(ve, ve + n));
        return ans;
    }
};