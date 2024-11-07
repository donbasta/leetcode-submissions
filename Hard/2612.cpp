class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        const int INF = 2e9;
        vector<int> dis(n, -1);
        vector<bool> ban(n);
        for (auto b : banned) ban[b] = true;

        set<int> s[2];
        for (int i = 0; i < n; i++) {
            if (ban[i]) continue;
            s[i & 1].insert(i);
        }

        queue<int> Q;
        dis[p] = 0;
        Q.push(p);
        s[p & 1].erase(p);

        auto get_right = [&](int t) -> pair<int, int> {
            pair<int, int> ret;
            int L, R;
            if (k & 1) {
                L = max(1, (k - 1) / 2 - t);
                R = min((n - 1 - t) - (k - 1) / 2, (k - 1) / 2);
                if (L > R) return make_pair(n, n);
                ret = make_pair(t + 2 * L, t + 2 * R);
            } else {
                L = max(0, k / 2 - 1 - t);
                R = min(n - 1 - t - (k / 2), (k - 2) / 2);
                if (L > R) return make_pair(n, n);
                ret = make_pair(t + 2 * L + 1, t + 2 * R + 1);
            }
            return ret;
        };

        auto get_left = [&](int x) -> pair<int, int> {
            pair<int, int> tmp = get_right(n - x - 1);
            if (tmp.first == n) return tmp;
            return make_pair(n - 1 - tmp.second, n - 1 - tmp.first);
        };

        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            pair<int, int> R = get_right(now), L = get_left(now);
            int p1 = R.first & 1;
            int p2 = L.first & 1;
            auto itr_r = s[p1].lower_bound(R.first);
            auto itr_l = s[p2].lower_bound(L.first);
            vector<int> t1, t2;
            while (true) {
                if (itr_r == s[p1].end()) break;
                if (*itr_r > R.second) break;
                assert(dis[*itr_r] == -1);
                dis[*itr_r] = dis[now] + 1;
                Q.push(*itr_r);
                t1.push_back(*itr_r);
                ++itr_r;
            }
            while (true) {
                if (itr_l == s[p2].end()) break;
                if (*itr_l > L.second) break;
                assert(dis[*itr_l] == -1);
                dis[*itr_l] = dis[now] + 1;
                Q.push(*itr_l);
                t2.push_back(*itr_l);
                ++itr_l;
            }
            for (auto t : t1) s[p1].erase(t);
            for (auto t : t2) s[p2].erase(t);
        }
        return dis;
    }

};