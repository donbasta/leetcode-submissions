class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        using ll = long long;
        ll cur = 0;
        int cnt = 0;
        for (auto c : text) {
            if (c == pattern[1]) {
                cur += cnt;
            }
            if (c == pattern[0]) {
                cnt++;
            }
        }
        // cout << cur << '\n';
        return cur + max(cnt, (int)count(text.begin(), text.end(), pattern[1]));
    }
};