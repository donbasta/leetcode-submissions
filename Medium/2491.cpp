class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        for (auto s : skill) sum += s;
        int n = skill.size();
        if (sum % (n / 2) != 0) return -1;
        long long sumPerTeam = sum / (n / 2);
        unordered_map<int, int> cnt;
        for (auto e : skill) {
            cnt[e]++;
        }
        long long ret = 0;
        long long tmp = 0;
        for (auto e : cnt) {
            int sk = e.first;
            if (sk * 2 == sumPerTeam) {
                if (e.second % 2 == 1) return -1;
                else ret += (1ll * sk * sk * (e.second / 2));
            } else {
                if (e.second != cnt[sumPerTeam - sk]) return -1;
                else tmp += 1ll * sk * (sumPerTeam - sk) * e.second;
            }
        }
        ret += tmp / 2;
        return ret;
    }
};