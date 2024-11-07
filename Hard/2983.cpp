class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        string s1 = s.substr(0, n / 2);
        string s2 = s.substr(n / 2, n / 2);
        reverse(s2.begin(), s2.end());

        vector<int> ps(n / 2), ss(n / 2);
        ps[0] = s1[0] == s2[0];
        for (int i = 1; i < n / 2; i++) {
            ps[i] = (ps[i - 1] + (s1[i] == s2[i]));
        }
        ss[n / 2 - 1] = s1[n / 2 - 1] == s2[n / 2 - 1];
        for (int i = n / 2 - 2; i >= 0; i--) {
            ss[i] = (ss[i + 1] + (s1[i] == s2[i]));
        }

        vector<vector<int>> p1(26, vector<int>(n / 2)), p2(26, vector<int>(n / 2));
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 26; j++) {
                p1[j][i] = (i ? p1[j][i - 1] : 0);
                p2[j][i] = (i ? p2[j][i - 1] : 0);
            }
            p1[s1[i] - 'a'][i]++;
            p2[s2[i] - 'a'][i]++;
        }

        auto get_freq = [&](int l, int r, int tp) -> vector<int> {
            vector<int> ret(26);
            for (int i = 0; i < 26; i++) {
                if (tp == 1) {
                    ret[i] = p1[i][r] - (l ? p1[i][l - 1] : 0);
                } else if (tp == 2) {
                    ret[i] = p2[i][r] - (l ? p2[i][l - 1] : 0);
                }
            }
            return ret;
        };

        vector<bool> ret;
        for (auto q : queries) {
            int a = q[0], b = q[1], c = n - 1 - q[3], d = n - 1 - q[2];
            assert ((a <= b) && (c <= d));
            int x = min(a, c), y = max(b, d);
            if (x > 0 && (ps[x - 1] < x)) {
                ret.push_back(false);
                continue;
            }
            if (y < n / 2 - 1 && (ss[y + 1] < n / 2 - 1 - y)) {
                ret.push_back(false);
                continue;
            }
            if (c > b || a > d) {
                vector<int> P1 = get_freq(a, b, 1);
                vector<int> P2 = get_freq(a, b, 2);
                vector<int> Q1 = get_freq(c, d, 1);
                vector<int> Q2 = get_freq(c, d, 2);
                vector<int> P = get_freq(x, y, 1);
                vector<int> Q = get_freq(x, y, 2);
                ret.push_back((P1 == P2) && (Q1 == Q2) && (P == Q));
            } else if (((c <= a) && (d >= b)) || ((a <= c) && (b >= d))) {
                vector<int> P = get_freq(x, y, 1);
                vector<int> Q = get_freq(x, y, 2);
                ret.push_back(P == Q);
            } else {
                vector<int> P = get_freq(x, y, 1);
                vector<int> Q = get_freq(x, y, 2);
                bool okP = true, okQ = true;
                if (a < c) {
                    assert (b < d);
                    vector<int> P1 = get_freq(a, b, 1);
                    vector<int> P2 = get_freq(a, c - 1, 2);
                    vector<int> Q1 = get_freq(b + 1, d, 1);
                    vector<int> Q2 = get_freq(c, d, 2);
                    for (int i = 0; i < 26; i++) {
                        okP &= P1[i] >= P2[i];
                        okQ &= Q2[i] >= Q1[i];
                    }
                } else if (a > c) {
                    assert (d < b);
                    vector<int> P1 = get_freq(a, b, 1);
                    vector<int> P2 = get_freq(d + 1, b, 2);
                    vector<int> Q1 = get_freq(c, a - 1, 1);
                    vector<int> Q2 = get_freq(c, d, 2);
                    for (int i = 0; i < 26; i++) {
                        okP &= P1[i] >= P2[i];
                        okQ &= Q2[i] >= Q1[i];
                    }
                }
                ret.push_back((P == Q) && okP && okQ);
            }
        }
        return ret;
    }
};