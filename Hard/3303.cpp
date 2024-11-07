using ll = long long;

int fpow(int a, int b, int mod) {
   int ret = 1;
   while (b) {
       if (b & 1) ret = (1ll * ret * a) % mod;
       a = (1ll * a * a) % mod;
       b >>= 1;
   }
   return ret;
}

struct RollingHash {
   const vector<int> B = {31, 37};
   const vector<int> M = {1000000007, 1000000009};
   vector<int> H[2], pw[2], ipw[2];
   int iB[2];
   RollingHash() {}
   RollingHash(const string& s) {
       int n = s.length();
       H[0].resize(n), H[1].resize(n);
       pw[0].resize(n + 1), pw[1].resize(n + 1);
       ipw[0].resize(n + 1), ipw[1].resize(n + 1);
       pw[0][0] = pw[1][0] = ipw[0][0] = ipw[1][0] = 1;
       for (int i = 0; i < 2; i++) {
           iB[i] = fpow(B[i], M[i] - 2, M[i]);
           for (int j = 1; j <= n; j++) {
               pw[i][j] = (1ll * pw[i][j - 1] * B[i]) % M[i];
               ipw[i][j] = (1ll * ipw[i][j - 1] * iB[i]) % M[i];
           }
           H[i][0] = (s[0] - 'a' + 1);
           for (int j = 1; j < n; j++) {
               H[i][j] = (1ll * H[i][j - 1] + 1ll * (s[j] - 'a' + 1) * pw[i][j]) % M[i];
           }
       }
   }
   pair<int, int> get_hash(int a, int b) {
       vector<int> X(2);
       for (int i = 0; i < 2; i++) {
           int hsh = (H[i][b] - (a ? H[i][a - 1] : 0)) % M[i];
           if (hsh < 0) hsh += M[i];
           hsh = (1ll * hsh * ipw[i][a]) % M[i];
           X[i] = hsh;
       }
       return make_pair(X[0], X[1]);
   }
};


class Solution {
public:
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    int minStartingIndex(string s, string pattern) {
    int n1 = s.length(), n2 = pattern.length();
    string cs = pattern + "#" + s;
    vector<int> pf = z_function(cs);
    int ans = INT_MAX;

    RollingHash rhs(s), rhpattern(pattern);

    for (int i = n2 + 1; i < n1 + n2 + 1; i++) {
        int k = pf[i];
        if (k == n2 || (k == n2 - 1 && i + k < n1 + n2 + 1)) {
            return i - n2 - 1;
        }
        if (i - 2 < n1 && rhpattern.get_hash(k + 1, n2 - 1) == rhs.get_hash(i + k - n2, i - 2)) {
            return i - n2 - 1;
        }
    }
    return -1;
    }
};

