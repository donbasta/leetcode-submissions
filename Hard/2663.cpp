class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = s.size();
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) tmp[i] = s[i] - 'a';
        int add = 1;
        for (int i = n - 1; i >= 0; i--) {
            tmp[i] += add;
            if (tmp[i] >= k) {
                tmp[i] = 0;
                add = 1;
            } else {
                add = 0;
            }
        }
        if (add == 1) {
            return "";
        }

        auto can = [&](int idx) -> bool {
            int cur = tmp[idx];
            cur++;
            while ((idx >= 1 && cur == tmp[idx - 1]) || (idx >= 2 && (cur == tmp[idx - 2]))) {
                cur++;
            }
            if (cur < k) {
                tmp[idx] = cur;
                return true;
            }
            return false;
        };

        auto construct = [&](int st) {
            vector<int> cant(k);
            if (st - 1 >= 0) cant[tmp[st - 1]] = true;
            if (st - 2 >= 0) cant[tmp[st - 2]] = true;
            for (int i = st; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    if (!cant[j]) {
                        tmp[i] = j;
                        break;
                    }
                }
                cant[tmp[i]] = true;
                if (i >= 2) cant[tmp[i - 2]] = false;
            }
        };

        for (int i = 1; i < n; i++) {
            if ((tmp[i] == tmp[i - 1]) || (i >= 2 && (tmp[i] == tmp[i - 2]))) {
                int cur = tmp[i];
                while ((cur == tmp[i - 1]) || (i >= 2 && (cur == tmp[i - 2]))) {
                    cur++;
                }
                if (cur < k) {
                    tmp[i] = cur;
                    construct(i + 1);
                    break;
                } else {
                    int piv = -1;
                    for (int j = i - 1; j >= 0; j--) {
                        if (can(j)) {
                            piv = j;
                            break;
                        }
                    }
                    if (piv == -1) return "";
                    construct(piv + 1);
                    break;
                }
            }
        }
        string ret(n, '\0');
        for (int i = 0; i < n; i++) ret[i] = (char)(tmp[i] + 'a');

        return ret;
    }
};