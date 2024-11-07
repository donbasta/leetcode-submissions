class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        unordered_map<int, int> ump;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == ')') ump[i] = tmp++;
        }
        vector<char> check;
        int mn = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                check.push_back(s[i]);
            } else if (s[i] == ')') {
                if (!check.empty() && check.back() == '(') check.pop_back();
                else mn++;
            }
        }
        mn += check.size();
        vector<string> ret;
        unordered_map<string, bool> ada;
        for (int i = 0; i < (1 << tmp); i++) {
            string lmao;
            int x = 0;
            bool cant = false;
            for (int j = 0; j < n; j++) {
                if ((ump.find(j) != ump.end()) && (i >> ump[j]) & 1) continue;
                lmao.push_back(s[j]);
                if (s[j] == '(') x++;
                else if (s[j] == ')') x--;
                if (x < 0) {
                    cant = true;
                    break;
                }
            }
            if (cant || (x > 0)) continue;
            if (lmao.size() != n - mn) continue;
            if (ada.find(lmao) == ada.end()) {
                ret.push_back(lmao);
                ada[lmao] = true;
            }
        }
        return ret;
    }
};