class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> se;
        for (auto b : wordList) se.insert(b);
        int len = beginWord.length();

        unordered_map<string, int> mp;
        queue<string> Q;
        mp[beginWord] = 0;
        Q.push(beginWord);
        while (!Q.empty()) {
            auto now = Q.front();
            int D = mp[now];
            Q.pop();
            for (int i = 0; i < len; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
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
        if (!mp.count(endWord)) return 0;
        return mp[endWord] + 1;
    }
};