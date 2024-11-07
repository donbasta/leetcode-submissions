class Solution {
public:
    int minNumberOfFrogs(string C) {
        int n = C.length();
        int tot = 0, avail = 0;
        map<char, char> prv;
        prv['r'] = 'c', prv['o'] = 'r', prv['a'] = 'o', prv['k'] = 'a';
        map<char, int> cnt;
        for (int i = 0; i < n; i++) {
            if (C[i] == 'c') {
                if (avail == 0) {
                    tot++;
                    avail++;
                }
                avail--;
                cnt['c']++;
            } else {
                if (cnt[prv[C[i]]] == 0) {
                    return -1;
                } else {
                    cnt[prv[C[i]]]--;
                    cnt[C[i]]++;
                    if (C[i] == 'k') {
                        avail++;
                    }
                }
            }
        }
        // cout << avail << ' ' << tot << '\n';
        if (avail != tot) return -1;
        return tot;
    }
};