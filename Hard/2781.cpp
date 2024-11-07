class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();
        set<string> se;
        const int INF = 2e9;
        vector<int> ri(n, INF);
        for (auto w : forbidden) se.insert(w);
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= 10; len++) {
                if (i + len - 1 >= n) break;
                string check = word.substr(i, len);
                if (se.count(check)) {
                    ri[i] = min(ri[i], i + len - 2);
                    break;
                }
            }
        }
        int ans = 0;
        int ptr = -1;
        set<pair<int, int>> itv;
        for (int i = 0; i < n; i++) {
            if (ptr < i - 1) ptr = i - 1;
            itv.insert(make_pair(ri[i], i));
            while (((ptr < n - 1) && (ptr < itv.begin()->first))) {
                ptr++;
                itv.insert(make_pair(ri[ptr], ptr));
            }
            ans = max(ans, min(ptr, itv.begin()->first) - i + 1);
            itv.erase(make_pair(ri[i], i));
        }
        return ans;
    }
};