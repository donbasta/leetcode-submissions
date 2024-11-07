class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        using ll = long long;
        set<vector<int>> se;
        int nn = (n + 1) / 2;
        int pw10 = 1;
        for (int i = 1; i < nn; i++) {
            pw10 *= 10;
        }
        ll ans = 0;

        ll fc[11];
        fc[0] = 1;
        for (int i = 1; i <= 10; i++) {
            fc[i] = (fc[i - 1] * i);
        }

        for (int i = pw10; i < pw10 * 10; i++) {
            string s = to_string(i);
            string cs = s;
            if (n & 1) cs.pop_back();
            reverse(cs.begin(), cs.end());
            s += cs;
            if (stoll(s) % k != 0) continue;
            vector<int> freq(10);
            for (auto c : s) {
                freq[c - '0']++;
            }
            if (se.count(freq)) {
                continue;
            }
            se.insert(freq);
            ll tmp = fc[n];
            for (int i = 0; i < 10; i++) tmp /= fc[freq[i]];
            if (freq[0] > 0) {
                ll t2 = fc[n - 1] / fc[freq[0] - 1];
                for (int i = 1; i < 10; i++) t2 /= fc[freq[i]];
                tmp -= t2;
            }
            ans += tmp;
        }
        return ans;
    }
};