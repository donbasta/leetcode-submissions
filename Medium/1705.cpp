class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = days.size();
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (apples[i] > 0) {
                mx = max(mx, i + days[i]);
            }
        }
        map<int, int> mp;
        int ret = 0;
        for (int i = 0; i <= mx; i++) {
            if (i < n && apples[i] > 0) {
                mp[i + days[i] - 1] += apples[i];
            }
            while (!mp.empty() && mp.begin()->first < i) mp.erase(mp.begin());
            if (!mp.empty()) {
                auto fi = mp.begin()->first;
                mp[fi]--;
                ret++;
                if (mp[fi] == 0) mp.erase(fi);
            }
        }
        return ret;
    }
};