class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ve(n);
        vector<int> mx(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                ve[i] = {nums[i], nums[i] * 2};
            } else {
                int tmp = nums[i];
                while (tmp % 2 == 0) {
                    ve[i].push_back(tmp);
                    tmp >>= 1;
                }
                ve[i].push_back(tmp);
                reverse(ve[i].begin(), ve[i].end());
            }
            mx[i] = ve[i].back();
        }

        set<pair<int, int>> se;
        for (int i = 0; i < n; i++) se.emplace(ve[i][0], i);
        int move = n;
        const int INF = 2e9;
        int ans = INF;
        while (move > 0) {
            int tmp = se.rbegin()->first - se.begin()->first;
            ans = min(ans, tmp);
            pair<int, int> now = *se.begin();
            se.erase(se.begin());
            if (now.first * 2 <= mx[now.second]) {
                se.emplace(now.first * 2, now.second);
            } else {
                move--;
                se.emplace(mx[now.second], now.second);
            }
        }
        return ans;
    }
};