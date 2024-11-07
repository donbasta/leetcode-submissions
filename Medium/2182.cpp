class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> cnt(26);
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) pq.emplace((char)(i + 'a'), cnt[i]);
        }
        string ret;
        char last = '\0';
        int cur = 0;
        while (!pq.empty()) {
            // cout << ret << ' ' << cur << ' ' << last << '\n';
            if (cur == repeatLimit) {
                if (pq.top().first == last) {
                    if (pq.size() == 1) return ret;
                    auto x1 = pq.top();
                    pq.pop();
                    auto x2 = pq.top();
                    pq.pop();
                    ret.push_back(x2.first);
                    last = x2.first;
                    cur = 1;
                    x2.second--;
                    if (x2.second > 0) {
                        pq.emplace(x2);
                    }
                    pq.emplace(x1);
                } else {
                    auto x1 = pq.top();
                    pq.pop();
                    assert (last != x1.first);
                    cur = 1;
                    last = x1.first;
                    ret.push_back(x1.first);
                    x1.second--;
                    if (x1.second > 0) {
                        pq.emplace(x1);
                    }
                }
            } else {
                if (pq.top().first == last) {
                    auto x1 = pq.top();
                    pq.pop();
                    ret.push_back(x1.first);
                    cur++;
                    x1.second--;
                    if (x1.second > 0) pq.emplace(x1);
                } else {
                    auto x1 = pq.top();
                    pq.pop();
                    ret.push_back(x1.first);
                    cur = 1;
                    last = x1.first;
                    x1.second--;
                    if (x1.second > 0) pq.emplace(x1);
                }
            }
        }
        return ret;
    
    }
};