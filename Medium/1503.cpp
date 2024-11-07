class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (auto e : left) {
            ans = max(ans, e);
        }
        for (auto e : right) {
            ans = max(ans, n - e);
        }
        return ans;
    }
};