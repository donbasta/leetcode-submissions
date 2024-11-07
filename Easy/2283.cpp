class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(10);
        for (auto c : num) {
            cnt[c - '0']++;
        }
        for (int i = 0; i < (int)num.length(); i++) {
            if (cnt[i] != num[i] - '0') return false;
        }
        return true;
    }
};