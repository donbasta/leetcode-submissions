class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (auto c : num) cnt[c - '0']++;
        int odd_occ = -1;
        for (int i = 9; i >= 0; i--) {
            if (cnt[i] & 1) {
                odd_occ = i;
                break;
            }
        }
        deque<char> de;
        if (odd_occ != -1) de.push_back((char)(odd_occ + '0'));
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < (cnt[i] / 2); j++) {
                de.push_back((char)(i + '0'));
                de.push_front((char)(i + '0'));
            }
        }
        while (!de.empty() && de.size() >= 2 && de.front() == '0' && de.back() == '0') {
            de.pop_front();
            de.pop_back();
        }
        if (de.empty()) return "0";
        string ret;
        while (!de.empty()) {
            ret.push_back(de.front());
            de.pop_front();
        }
        return ret;
    }
};