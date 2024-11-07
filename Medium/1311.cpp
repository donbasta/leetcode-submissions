class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        const int INF = 2e9;
        vector<int> D(n, INF);
        queue<int> Q;
        Q.push(id);
        D[id] = 0;
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : friends[now]) {
                if (D[c] != INF) continue;
                D[c] = D[now] + 1;
                Q.push(c);
            }
        }
        vector<vector<int>> dis(n);
        for (int i = 0; i < n; i++) {
            if (D[i] == INF) continue;
            dis[D[i]].push_back(i);
        }
        map<string, int> freq;
        for (auto id : dis[level]) {
            for (auto w : watchedVideos[id]) {
                freq[w]++;
            }
        }
        vector<pair<int, string>> ve;
        for (auto f : freq) {
            ve.emplace_back(f.second, f.first);
        }
        sort(ve.begin(), ve.end());
        vector<string> ans;
        for (auto e : ve) {
            ans.push_back(e.second);
        }
        return ans;
    }
};