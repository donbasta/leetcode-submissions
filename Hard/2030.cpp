class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        string ret;
        int sisa = 0;
        for (auto c : s) sisa += (c == letter);
        int cur = 0;
        int idx = 0;
        int n = s.size();
        for (auto c : s) {
            if (c == letter) {
                while (!ret.empty() && (ret.back() > c) && (ret.size() + n - 1 - idx >= k)) {
                    ret.pop_back();
                }
                ret.push_back(c);
                cur++;
                sisa--;
            } else {
                while (!ret.empty() && (ret.back() > c) && (ret.size() + n - 1 - idx >= k)) {
                    if (ret.back() == letter) {
                        if (cur - 1 + sisa >= repetition) {
                            ret.pop_back();
                            cur--;
                        } else {
                            break;
                        }
                    } else {
                        ret.pop_back();
                    }
                }
                if (ret.size() + 1 + repetition - cur <= k) ret.push_back(c);
            }
            idx++;
        }
        while (ret.size() > k) ret.pop_back();
        return ret;
    }
};