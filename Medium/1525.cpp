class Solution {
public:
    int numSplits(string s) {
        set<int> se;
        int n = (int)s.length();
        vector<int> pre(n + 1), suf(n + 1);
        for(int i = 0 ; i < n - 1; i++) {
            se.insert(s[i]);
            pre[i] = (int)se.size();
        }
        se.clear();
        for(int i = n - 1; i >= 1; i--) {
            se.insert(s[i]);
            suf[i] = (int)se.size();
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            if(pre[i] == suf[i + 1]) ans++;
        }
        return ans;
    }
};