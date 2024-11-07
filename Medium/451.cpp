class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s) {
            cnt[c]++;
        }
        string tmp;
        for (auto c : cnt) {
            tmp.push_back(c.first);
        }
        sort (tmp.begin(), tmp.end(), [&](char a, char b) -> bool {
            return cnt[a] > cnt[b];
        });
        string ans;
        for (auto c : tmp) {
            for (int i = 0; i < cnt[c]; i++) {
                ans.push_back(c);
            }
        }
        return ans;
    }
};