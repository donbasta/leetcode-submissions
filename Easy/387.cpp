class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26);
        for (auto e : s) cnt[e - 'a']++;
        int idx = 0;
        for (auto e : s) {
            if (cnt[e - 'a'] == 1) return idx;
            idx++;
        }
        return -1;
    }
};