class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ret;
        int n = variables.size();
        for (int i = 0; i < n; i++) {
            int x = 1;
            for (int j = 0; j < variables[i][1]; j++) {
                x = (1ll * x * variables[i][0]) % 10;
            }
            int y = 1;
            for (int j = 0; j < variables[i][2]; j++) {
                y = (1ll * y * x) % variables[i][3];
            }
            if (y == target) ret.push_back(i);
        }
        return ret;
    }
};