class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<vector<int>> pos(k);
        int n = rolls.size();
        for (int i = 0; i < n; i++) {
            pos[--rolls[i]].push_back(i);
        }
        int ans = 0;
        int lastPos = -1;
        while (true) {
            int mxTemp = lastPos;
            for (int i = 0; i < k; i++) {
                int hihi = upper_bound(pos[i].begin(), pos[i].end(), lastPos) - pos[i].begin();
                if (hihi == pos[i].size()) {
                    return ans + 1;
                }
                mxTemp = max(mxTemp, pos[i][hihi]);
            }
            lastPos = mxTemp;
            ans++;
        }
        return ans + 1;
    }
};