class Solution {
public:
    int minChanges(string s) {
        vector<int> parts;
        char cur = s[0];
        int len = 1;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i] != cur) {
                parts.push_back(len);
                len = 1;
                cur = s[i];
            } else {
                len++;
            }
        }
        parts.push_back(len);
        int ans = 0;
        while (!parts.empty()) {
            int c = parts.back();
            parts.pop_back();
            if (c & 1) {
                ans++;
                assert (!parts.empty());
                parts.back()++;
            }
        } 
        return ans;
    }
};