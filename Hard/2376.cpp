class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int len = s.length();
        int ans = 0, tmp = 10, byk = 9;
        for (int i = 1; i < len; i++) {
            ans += byk;
            byk *= --tmp;
        }
        vector<vector<int>> C(11, vector<int>(11));
        for (int i = 0; i <= 10; i++) C[0][i] = 1;
        for (int i = 1; i <= 10; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= 10; j++) {
                C[i][j] = C[i - 1][j - 1] * j;
            }
        }
        vector<int> cnt(10);
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                cnt[0]++;
                if (cnt[0] > 1) {
                    break;
                } else {
                    continue;
                }
            }
            int cur = s[i] - '0';
            for (int j = 0; j < cur; j++) {
                if (i == 0 && j == 0) continue;
                if (cnt[j] > 0) continue;
                ans += C[len - i - 1][9 - i]; //(9 - i)(8 - i) ... sebanyak len - i - 1
            }
            cnt[cur]++;
            if (cnt[cur] > 1) {
                break;
            } else {
                continue;
            }
        }
        bool ok = true;
        for (int i = 0; i < 10; i++) {
            if (cnt[i] > 1) {
                ok = false;
                break;
            }
        }
        ans += ok;
        return ans;
    }
};