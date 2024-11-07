class Solution {
public:
    bool isRationalEqual(string s, string t) {
        long long pw[19];
        pw[0] = 1;
        for (int i = 1; i < 19; i++) {
            pw[i] = pw[i - 1] * 10;
        }
        auto convert = [&](string x) -> pair<long long, long long> {
            string tmp;
            int n = x.length();
            int t = 0;
            long long A = -1, B = -1, C = -1;
            int b = 0, c = 0;
            for (int i = 0; i < n; i++) {
                if (x[i] == '.') {
                    t++;
                    A = stoll(tmp);
                    tmp.clear();
                } else if (x[i] == '(') {
                    t++;
                    if (!tmp.empty()) {
                        B = stoll(tmp);
                    } 
                    tmp.clear();
                } else if (x[i] == ')') {
                    C = stoll(tmp);
                } else {
                    tmp.push_back(x[i]);
                    if (t == 1) b++;
                    else if (t == 2) c++;
                }
            }
            // cout << A << ' ' << B << ' ' << C << '\n';
            if (A == -1) {
                A = stoll(tmp);
                return make_pair(A, 1);
            } else if (B == -1) {
                if (C == -1) {
                    if (!tmp.empty()) {
                        B = stoll(tmp);
                    } else {
                        B = 0;
                    }
                    return make_pair(A * pw[b] + B, pw[b]);
                } else {
                    return make_pair(A * (pw[c] - 1) + C, pw[c] - 1);
                }
            } else {
                assert (C != -1);
                return make_pair(A * (pw[c] - 1) * pw[b] + B * (pw[c] - 1) + C, pw[b] * (pw[c] - 1));
            }
        };
        auto [sa, sb] = convert(s);
        auto [ta, tb] = convert(t);
        // cout << sa << ' ' << sb << ' ' << ta << ' ' << tb << '\n';
        return (sa * tb == sb * ta);
    }
};