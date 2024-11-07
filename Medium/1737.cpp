class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> ca(26), cb(26);
        for (auto c : a) ca[c - 'a']++;
        for (auto c : b) cb[c - 'a']++;
        int ma = *max_element(ca.begin(), ca.end());
        int mb = *max_element(cb.begin(), cb.end());
        int la = a.length(), lb = b.length();
        int ans = (la - ma) + (lb - mb);
        for (int i = 0; i < 25; i++) {
            int tmp = 0;
            for (auto c : a) if ((c - 'a') >= i + 1) tmp++;
            for (auto c : b) if ((c - 'a') <= i) tmp++;
            ans = min(ans, tmp);
        }
        for (int i = 0; i < 25; i++) {
            int tmp = 0;
            for (auto c : b) if ((c - 'a') >= i + 1) tmp++;
            for (auto c : a) if ((c - 'a') <= i) tmp++;
            ans = min(ans, tmp);
        }
        return ans;
    }
};