class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prv = -1;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) continue;
            if (i > prv + 1) {
                if (prv > -1) ans = max(ans, (i - prv) / 2);
                else ans = max(ans, i);
            }
            prv = i;
        }
        if (n > prv + 1) {
            ans = max(ans, n - 1 - prv);
        }
        return ans;
    }
};