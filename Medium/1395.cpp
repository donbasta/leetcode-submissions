class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int p1 = 0, p2 = 0, q1 = 0, q2 = 0;
            for (int j = 0; j < i; j++) {
                p1 += rating[j] < rating[i];
                p2 += rating[j] > rating[i];
            }
            for (int j = i + 1; j < n; j++) {
                q1 += rating[i] < rating[j];
                q2 += rating[i] > rating[j];
            }
            ans += p1 * q1 + p2 * q2;
        }
        return ans;
    }
};