class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k >= 2) {
            sort(s.begin(), s.end());
            return s;
        }
        string mn = s;
        string tmp = s;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            char lol = tmp[0];
            for (int j = 0; j < n - 1; j++) {
                tmp[j] = tmp[j + 1];
            }
            tmp[n - 1] = lol;
            mn = min(mn, tmp);
        }
        return mn;
    }
};