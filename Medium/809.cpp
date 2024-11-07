class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        const function<vector<pair<char, int>>(string)> convert = [&](string x) -> vector<pair<char, int>> {
            int cur_char = s[0];
            int cur_len = 1;
            vector<pair<char, int>> ret;
            for (int i = 1; i < x.length(); i++) {
                if (x[i] == x[i - 1]) cur_len++;
                else {
                    ret.emplace_back(cur_char, cur_len);
                    cur_char = x[i];
                    cur_len = 1;
                }
            }
            ret.emplace_back(cur_char, cur_len);
            return ret;
        };
        vector<pair<char, int>> S = convert(s);
        int ans = 0;
        for (auto w : words) {
            vector<pair<char, int>> W = convert(w);
            if (W.size() != S.size()) continue;
            int n = W.size();
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (S[i].first != W[i].first) {
                    ok = false; break;
                } else if (S[i].second < W[i].second) {
                    ok = false;
                    break;
                } else if (S[i].second > W[i].second) {
                    if (S[i].second < 3) {
                        ok = false;
                        break;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};