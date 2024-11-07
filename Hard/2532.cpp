class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<pair<int, int>> L, R;
        int sz = time.size();
        for (int i = 0; i < sz; i++) {
            L.emplace(time[i][0] + time[i][2], i);
        }
        int now;
        int rem = n;
        map<int, vector<pair<int, int>>> ev;
        ev[0].emplace_back(-1, 2);

        int ans = 0;
        bool st = false;
        for (auto e : ev) {
            now = e.first;
            for (auto x : e.second) {
                int id = x.first;
                if (x.second == 1) {
                    R.emplace(time[id][0] + time[id][2], id);
                } else if (x.second == 0) {
                    L.emplace(time[id][0] + time[id][2], id);
                } else if (x.second == 2) {
                    st = true;
                }
            }
            if (st) {
                if (!R.empty()) {
                    auto take = R.top();
                    R.pop();
                    int id = take.second;
                    ans = max(ans, now + time[id][2]);
                    ev[now + time[id][2]].emplace_back(-1, 2);
                    ev[now + time[id][2] + time[id][3]].emplace_back(id, 0);
                    st = false;
                } else if ((!L.empty()) && rem > 0) {
                    rem--;
                    auto take = L.top();
                    L.pop();
                    int id = take.second;
                    ev[now + time[id][0]].emplace_back(-1, 2);
                    ev[now + time[id][0] + time[id][1]].emplace_back(id, 1);
                    st = false;
                }
            }
        }
        return ans;
    }
};