class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int itr = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        while (itr < n && s[itr] == 'M') { a++, itr++; }
        if (itr <= n - 2 && s.substr(itr, 2) == "CD") {
            b = 4, itr += 2;
        } else if (itr <= n - 2 && s.substr(itr, 2) == "CM") {
            b = 9, itr += 2;
        } else {
            while (itr < n && (s[itr] == 'C' || s[itr] == 'D')) {
                if (s[itr] == 'C') b++;
                else b += 5;
                itr++;
            }
        }
        if (itr <= n - 2 && s.substr(itr, 2) == "XL") {
            c = 4, itr += 2;
        } else if (itr <= n - 2 && s.substr(itr, 2) == "XC") {
            c = 9, itr += 2;
        } else {
            while (itr < n && (s[itr] == 'X' || s[itr] == 'L')) {
                if (s[itr] == 'X') c++;
                else c += 5;
                itr++;
            }
        }
        if (itr <= n - 2 && s.substr(itr, 2) == "IV") {
            d = 4, itr += 2;
        } else if (itr <= n - 2 && s.substr(itr, 2) == "IX") {
            d = 9, itr += 2;
        } else {
            while (itr < n && (s[itr] == 'I' || s[itr] == 'V')) {
                if (s[itr] == 'I') d++;
                else d += 5;
                itr++;
            }
        }
        // cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
        return (a * 1000 + b * 100 + c * 10 + d);
    }
};