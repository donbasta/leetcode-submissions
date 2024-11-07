class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> dif(n + 1);
        for (auto v : shifts) {
            int ch = (v[2] == 0 ? -1 : 1);
            dif[v[0]] += ch;
            dif[v[1] + 1] -= ch;
        }
        for (int i = 1; i < n; i++) {
            dif[i] += dif[i - 1];
        }
        string ret;
        for (int i = 0; i < n; i++) {
            dif[i] %= 26;
            if (dif[i] < 0) dif[i] += 26;
            int nw = ((s[i] - 'a') + dif[i]) % 26;
            ret.push_back((char)(nw + 'a'));
        }
        return ret;
    }
};