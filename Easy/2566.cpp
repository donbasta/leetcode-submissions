class Solution {
public:
    int minMaxDifference(int num) {
        string lol = to_string(num);
        int n = lol.length();
        string lolMax = lol, lolMin = lol;
        char amx = lol[0], amn = lol[0];
        int i = 0;
        while (i < n && lol[i] == '9') {
            i++;
        }
        if (i < n) amx = lol[i];
        i = 0;
        while (i < n && lol[i] == '0') {
            i++;
        }
        if (i < n) amn = lol[i];

        for (int i = 0; i < n; i++) {
            if (lolMax[i] == amx) lolMax[i] = '9';
            if (lolMin[i] == amn) lolMin[i] = '0';
        }
        int mx = stoi(lolMax);
        int mn = stoi(lolMin);
        return mx - mn;
    }
};