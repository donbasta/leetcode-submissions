class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        map<string, bool> mp;
        map<string, bool> pa;
        mp[""] = true;
        for (auto w : words) {
            reverse(w.begin(), w.end());
            string cur = "";
            for (auto c : w) {
                pa[cur] = true;
                cur += c;
                mp[cur] = true;
            }
        }
        int ans = 0;
        for (auto x : mp) {
            if (!pa[x.first]) ans += x.first.length() + 1;
        }
        return ans;
    }
};