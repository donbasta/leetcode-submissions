class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort (items.begin(), items.end(), [&](const vector<int>& a, const vector<int>& b) -> bool {
            return a[0] > b[0];
        });
        int n = items.size();
        vector<int> cnt(n + 1);
        long long tot = 0;
        int cur_dif = 0;
        vector<multiset<int>> lmao(n + 1);
        set<pair<int, int>> se;
        for (int i = 0; i < k; i++) {
            tot += items[i][0];
            cnt[items[i][1]]++;
            if (cnt[items[i][1]] == 1) cur_dif++;
            lmao[items[i][1]].insert(items[i][0]);
            if (cnt[items[i][1]] > 1) {
                se.emplace(*lmao[items[i][1]].begin(), items[i][1]);
            }
        }
        tot += 1ll * (cur_dif) * (cur_dif);
        long long ans = tot;
        for (int i = k; i < n; i++) {
            if (se.empty()) break;
            if (cnt[items[i][1]] > 0) continue;   
            auto buang = *se.begin();
            se.erase(buang);
            lmao[buang.second].erase(lmao[buang.second].find(buang.first));
            cnt[buang.second]--;
            cnt[items[i][1]]++;
            if (cnt[buang.second] > 1) {
                se.emplace(*lmao[buang.second].begin(), buang.second);
            }
            tot -= buang.first;
            tot += items[i][0];
            tot += (2 * cur_dif + 1);
            cur_dif++;
            ans = max(ans, tot);
        }
        return ans;
    }
};