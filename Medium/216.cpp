class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        for (int i = 0; i < (1 << 9); i++) {
            if (__builtin_popcount(i) != k) continue;
            int sum = 0;
            for (int j = 0; j < 9; j++) {
                if ((i >> j) & 1) sum += (j + 1);
            }
            if (sum != n) continue;
            vector<int> tmp;
            for (int j = 0; j < 9; j++) {
                if ((i >> j) & 1) tmp.push_back(j + 1);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};