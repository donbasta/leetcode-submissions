class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> ve;
        int cur_len = 1;
        char cur_char = s[0];
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i] != cur_char) {
                if (cur_len > 0) {
                    ve.emplace_back(cur_len, cur_char);
                    cur_len = 1;
                } else {
                    if (!ve.empty() && ve.back().second == s[i]) {
                        cur_len = ve.back().first + 1;
                        if (cur_len >= k) cur_len -= k;
                        ve.pop_back();
                    } else {    
                        cur_len = 1;
                    }
                }
                cur_char = s[i];
            } else {
                cur_len++;
                if (cur_len >= k) cur_len -= k;
            }
        }
        if (cur_len > 0) ve.emplace_back(cur_len, cur_char);
        string ret;
        for (auto e : ve) {
            for (int i = 0; i < e.first; i++) {
                ret += e.second;
            }
        }
        return ret;
    }
};