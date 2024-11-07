class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> T = colors;
        for (int i = 0; i < k - 1; i++) {
            T.push_back(colors[i]);
        }
        for (int i = 0; i < k + n - 1; i += 2) {
            T[i] ^= 1;
        }
        vector<int> ri(n + k - 1, -1);
        ri[n + k - 2] = n + k - 2;
        for (int i = n + k - 3; i >= 0; i--) {
            if (T[i] == T[i + 1]) ri[i] = ri[i + 1];
            else ri[i] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (ri[i] >= i + k - 1) {
                ans++;
            }
        }
        return ans;
    }
};