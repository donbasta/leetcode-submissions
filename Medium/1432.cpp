class Solution {
public:
    int maxDiff(int num) {
        string snum = to_string(num);
        int n = snum.length();
        string mx = snum, mn = snum;
        char to_rep, jadi;
        int start = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 && snum[i] > '1') {
                to_rep = snum[i];
                jadi = '1';
                start = i;
                break;
            } else if (i > 0 && snum[i] > '0' && snum[i] != snum[0]) {
                to_rep = snum[i];
                jadi = '0';
                start = i;
                break;
            }
        }
        if (start != -1) {
            for (int i = start; i < n; i++) {
                if (snum[i] == to_rep) mn[i] = jadi;
            }
        }
        start = -1;
        for (int i = 0; i < n; i++) {
            if (snum[i] < '9') {
                to_rep = snum[i];
                start = i;
                break;
            }
        }
        if (start != -1) {
            for (int i = start; i < n; i++) {
                if (snum[i] == to_rep) mx[i] = '9';
            }
        }
        return stoi(mx) - stoi(mn);
    }
};