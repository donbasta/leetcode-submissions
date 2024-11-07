class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        const int INF = 2e9;
        vector<int> cnt(26, INF);
        for (auto w : words) {
            vector<int> ada(26);
            for (auto c : w) ada[c - 'a']++;
            for (int i = 0; i < 26; i++) cnt[i] = min(cnt[i], ada[i]);
        }
        vector<string> ve;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                string str;
                str.push_back((char)(i + 'a'));
                ve.push_back(str);
            }
        }
        return ve;
    }
};