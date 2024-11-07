class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<int> idx[n + 1];
        for (int i = 0; i < n; i++) {
            idx[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> groups;
        for (int i = 1; i <= n; i++) {
            int countGroups = (idx[i].size() / i);
            int id = 0;
            for (int j = 0; j < countGroups; j++) {
                vector<int> indices;
                for (int k = 0; k < i; k++) {
                    indices.push_back(idx[i][id++]);
                }
                groups.push_back(indices);
            }
        }
        return groups;
    }
};