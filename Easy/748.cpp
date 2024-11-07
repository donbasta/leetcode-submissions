class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26);
        for (auto c : licensePlate) {
            if (c >= 'A' && c <= 'Z') {
                cnt[c - 'A']++;
            } else if (c >= 'a' && c <= 'z') {
                cnt[c - 'a']++;
            }
        }
        string st;
        int mn = INT_MAX;
        for (auto w : words) {
            vector<int> tmp(26);
            for (auto c : w) tmp[c - 'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > tmp[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok && (w.length() < mn)) {
                st = w;
                mn = w.length();
            }
        }
        return st;
    }
};