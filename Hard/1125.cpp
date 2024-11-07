class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size();
        int m = req_skills.size();
        const int INF = 2e9;
        vector<vector<int>> dp(n, vector<int>(1 << m, INF));
        vector<vector<pair<pair<int, int>, bool>>> prv(n, vector<pair<pair<int, int>, bool>>(1 << m));
        
        unordered_map<string, int> mp;
        for (int i = 0; i < m; i++) {
            mp[req_skills[i]] = i;
        }
        vector<int> skills(n);
        for (int i = 0; i < n; i++) {
            for (auto e : people[i]) {
                skills[i] ^= (1 << mp[e]);
            }
        }
        for (int i = 0; i < n; i++) dp[i][0] = 0;
        for (int i = skills[0]; i > 0; i = (i - 1) & skills[0]) {
            dp[0][i] = 1;
            prv[0][i] = make_pair(make_pair(-1, 0), true);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                int A = dp[i - 1][j];
                int B = 1 + dp[i - 1][j & (~skills[i])];
                if (A <= B) {
                    prv[i][j] = make_pair(make_pair(i - 1, j), false);
                } else {
                    prv[i][j] = make_pair(make_pair(i - 1, j & (~skills[i])), true);
                }
                dp[i][j] = min(A, B);
            }
        }

        // cout << dp[n - 1][(1 << m) - 1] << '\n';
        vector<int> ret;
        pair<int, int> cur_state = make_pair(n - 1, (1 << m) - 1);
        while (cur_state.second) {
            // cout << cur_state.second << ' ' << cur_state.first << '\n';
            if (prv[cur_state.first][cur_state.second].second) {
                ret.push_back(cur_state.first);
            }
            cur_state = prv[cur_state.first][cur_state.second].first;
        }
        return ret;
    }
};