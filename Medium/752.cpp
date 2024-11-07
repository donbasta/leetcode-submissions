class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> cant;
        for (auto d : deadends) cant.insert(d);

        if (cant.count("0000")) return -1;

        set<string> vis;
        queue<pair<string, int>> Q;
        Q.emplace("0000", 0);
        vis.insert("0000");
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            string cur = now.first;
            int dis = now.second;
            if (cur == target) {
                return dis;
            }
            for (int i = 0; i < 4; i++) {
                int cur_dig = cur[i] - '0';
                for (auto nx : {(cur_dig + 9) % 10, (cur_dig + 1) % 10}) {
                    char c = (char)nx + '0';
                    cur[i] = c;
                    if (vis.count(cur) || cant.count(cur)) {
                        cur[i] = (char)(cur_dig + '0');
                        continue;
                    }
                    vis.insert(cur);
                    Q.emplace(cur, dis + 1);
                    cur[i] = (char)(cur_dig + '0');
                }
            }
        }
        return -1;
        assert (false);
    }
};