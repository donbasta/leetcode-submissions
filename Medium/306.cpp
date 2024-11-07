class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
    
        using ll = long long;
        for (int i = 0; i <= n - 3; i++) {
            if (num[0] == '0' && i != 0) continue;
            for (int j = i + 1; j <= n - 2; j++) {
                if (num[i + 1] == '0' && j != i + 1) continue;
                ll x = stoll(num.substr(0, i + 1));
                ll y = stoll(num.substr(i + 1, j - i));
                int ptr = j + 1;
                bool ok = true;
                while (true) {
                    ll now = x + y;
                    if (num[ptr] == '0' && now != 0) {
                        ok = false;
                        break;
                    }
                    string tmp = to_string(now);
                    int k = 0;
                    while (ptr < n && num[ptr] == tmp[k]) {
                        ptr++, k++;
                    }
                    if (k != tmp.length()) {
                        ok = false;
                        break;
                    }
                    if (ptr == n) {
                        break;
                    }
                    x = y;
                    y = now;
                }
                if (ok) return true;
            }
        }
        return false;
    }
};