class Solution {
public:
    int minOperations(vector<string>& logs) {
        int dep = 0;
        for (auto l : logs) {
            if (l == "../") {
                dep = max(dep - 1, 0);
            } else if (l != "./") {
                dep++;
            }
        }
        return dep;
    }
};