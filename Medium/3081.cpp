class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();
        int qm = 0;
        vector<int> cnt(26);
        for (auto c : s) {
            if (c == '?') qm++;
            else cnt[c - 'a']++;
        }
        set<pair<int, int>> se;
        for (int i = 0; i < 26; i++) se.emplace(cnt[i], i);
        vector<char> take;
        for (int i = 0; i < qm; i++) {
            auto tmp = *se.begin();
            se.erase(se.begin());
            cnt[tmp.second]++;
            take.push_back(tmp.second);
            se.emplace(cnt[tmp.second], tmp.second);
        }
        sort(take.begin(), take.end());
        int ptr = 0;
        for (auto& c : s) {
            if (c == '?') c = (char)(take[ptr++] + 'a');
        }
        return s;
    }
};