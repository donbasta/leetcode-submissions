class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        vector<int> segs;
        char cur = s[0];
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == cur) len++;
            else {
                segs.push_back(len);
                cur = s[i];
                len = 1;
            }
        }
        segs.push_back(len);
        int ans = 0;
        for (int i = 0; i < (int)segs.size() - 1; i++) {
            ans += min(segs[i], segs[i + 1]);
        }
        return ans;
    }
};