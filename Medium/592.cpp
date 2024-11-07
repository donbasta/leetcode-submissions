class Solution {
public:
    string fractionAddition(string expression) {
        int a = 0, b = 1;
        string ca, cb;
        bool den = false;

        auto add = [&]() {
            int x = stoi(ca), y = stoi(cb);
            long long ta = 1ll * a * y + 1ll * b * x;
            long long tb = 1ll * b * y;
            long long fpb = abs(__gcd(ta, tb));
            ta /= fpb, tb /= fpb;
            a = ta, b = tb;
        };

        for (auto c : expression) {
            if (c == '-' || c == '+') {
                if (!ca.empty()) {
                    add();
                    ca.clear(), cb.clear(), den = false;
                }
                if (c == '-') ca.push_back(c);
            } else if (c == '/') {
                den = true;
            } else {
                if (den) cb.push_back(c);
                else ca.push_back(c);
            }
        }
        add();
        string ret;
        ret += to_string(a);
        ret += '/';
        ret += to_string(b);
        return ret;
    }
};