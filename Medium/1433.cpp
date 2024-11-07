class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> cnt1(26), cnt2(26);
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        vector<int> tmp1 = cnt1, tmp2 = cnt2;
        int hihi = 0;
        for (int i = 25; i >= 0; i--) {
            // cout << i << ' ' << cnt1[i] << ' ' << cnt2[i] << '\n';
            if (tmp1[i] > tmp2[i]) break;
            hihi++;
            int sisa = tmp2[i] - tmp1[i];
            if (i > 0) tmp2[i - 1] += sisa;
        }
        if (hihi == 26) return true;
        tmp1 = cnt2, tmp2 = cnt1;
        hihi = 0;
        for (int i = 25; i >= 0; i--) {
            // cout << i << ' ' << cnt1[i] << ' ' << cnt2[i] << '\n';
            if (tmp1[i] > tmp2[i]) return false;
            hihi++;
            int sisa = tmp2[i] - tmp1[i];
            if (i > 0) tmp2[i - 1] += sisa;
        }
        return true;
    }
};