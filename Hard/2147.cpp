class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int> seat_positions;
        int n = corridor.size();
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                seat_positions.push_back(i);
            }
        }
        int count_seats = seat_positions.size();
        if ((count_seats == 0) || (count_seats & 1)) return 0;
        
        const int MOD = 1e9 + 7;
        int ans = 1;
        for (int i = 1; i + 1 < count_seats; i += 2) {
            ans = (1ll * ans * (seat_positions[i + 1] - seat_positions[i])) % MOD;
        }
        return ans;
    }
};