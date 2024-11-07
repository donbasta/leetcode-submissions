class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> to(n);
        for (auto e : edges) {
            to[e[1]]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (to[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};