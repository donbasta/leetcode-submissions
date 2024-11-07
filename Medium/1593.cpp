class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.length();
        int ans = 1;
        for (int i = 0; i < (1 << (n - 1)); i++) {
            set<string> se;
            vector<int> sep = {-1};
            for (int j = 0; j < n - 1; j++) {
                if ((i >> j) & 1) sep.push_back(j);
            }
            sep.push_back(n - 1);
            bool ok = true;
            for (int i = 1; i < (int)sep.size(); i++) {
                string cur = s.substr(sep[i - 1] + 1, sep[i] - sep[i - 1]);
                if (se.count(cur)) {
                    ok = false;
                    break;
                }
                se.insert(cur);
            }
            if (ok) {
                ans = max(ans, (int)sep.size() - 1);
            }
        }
        return ans;
    }
};