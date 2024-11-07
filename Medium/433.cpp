class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> se;
        for (auto b : bank) se.insert(b);

        unordered_map<string, int> mp;
        queue<string> Q;
        mp[startGene] = 0;
        Q.push(startGene);
        while (!Q.empty()) {
            auto now = Q.front();
            int D = mp[now];
            Q.pop();
            for (int i = 0; i < 8; i++) {
                for (char c : "ACGT") {
                    if (c == now[i]) continue;
                    char tmp = now[i];
                    now[i] = c;
                    if (!se.count(now)) { now[i] = tmp; continue; }
                    if (mp.count(now)) { now[i] = tmp; continue; }
                    mp[now] = D + 1;
                    Q.push(now);
                    now[i] = tmp;
                }
            }
        }
        if (!mp.count(endGene)) return -1;
        return mp[endGene];
    }
};