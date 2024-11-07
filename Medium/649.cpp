class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0, d = 0;
        for (auto se : senate) r += (se == 'R'), d += (se == 'D');
        int n = senate.length();
        vector<bool> can(n, true);
        int idx = 0;
        while ((r > 0) && (d > 0)) {
            if (!can[idx]) {
                idx = (idx + 1) % n; 
                continue;
            };
            int cur = senate[idx];
            int other = (cur == 'R' ? 'D' : 'R');
            int j = (idx + 1) % n;
            while (j != idx) {
                if ((senate[j] == cur) || (!can[j])) {
                    j = (j + 1) % n;
                    continue;
                }
                if (other == 'R') {
                    r--;
                } else {
                    d--;
                }
                can[j] = false;
                break;
            }
            idx = (idx + 1) % n;
        }
        if (r > 0) return "Radiant";
        return "Dire";
    }
};