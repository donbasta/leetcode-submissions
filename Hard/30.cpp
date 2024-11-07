class Solution {
public:
    int fpow(int a, int b, int mod) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1ll * ret * a) % mod;
            a = (1ll * a * a) % mod;
            b >>= 1;
        }
        return ret;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length();
        int n = s.length();
        const int B = 31, P = 1e9 + 9;
        int iB = fpow(B, P - 2, P);
        vector<int> pw(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++) {
            pw[i] = (1ll * pw[i - 1] * B) % P;
        }
        multiset<int> M;
        int wlen = words.size();
        for (auto w : words) {
            int tmp = 0;
            for (int i = 0; i < len; i++) {
                tmp = ((1ll * (w[i] - 'a' + 1) * pw[i]) + tmp) % P;
            }
            M.insert(tmp);
        }
        vector<int> hashes(n - len + 1);
        int tmp = 0;
        for (int i = 0; i < len - 1; i++) {
            tmp = ((1ll * (s[i] - 'a' + 1) * pw[i]) + tmp) % P;
        }
        for (int i = len - 1; i < n; i++) {
            tmp = ((1ll * (s[i] - 'a' + 1) * pw[len - 1]) + tmp) % P; 
            hashes[i - len + 1] = tmp;
            tmp = (tmp - (s[i - len + 1] - 'a' + 1)) % P;
            tmp = (1ll * tmp * iB) % P;
            if (tmp < 0) tmp += P;
        }
        vector<int> ret;
        for (int i = 0; i < len; i++) {
            multiset<int> lmao;
            for (int j = i; j <= n - len; j += len) {
                lmao.insert(hashes[j]);
                if (lmao.size() > wlen) lmao.erase(lmao.find(hashes[j - wlen * len]));
                if (lmao.size() == wlen) {
                    if (lmao == M) {
                        ret.push_back(j - (wlen - 1) * len);
                    }
                }
            }
        }
        return ret;
    }
};