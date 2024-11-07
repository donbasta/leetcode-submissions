using ll = long long;
using matrix = vector<vector<ll>>;
const int MOD = 1e9 + 7;

matrix id;

matrix mul(matrix a, matrix b) {
    int sz = (int)a.size();
    matrix d(sz, vector<ll>(sz));
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                d[i][j] = (d[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return d;
}

matrix fpow(matrix a, ll b) {
    matrix ret = id;
    while (b) {
        if (b & 1)
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        id.assign(26, vector<ll>(26));
        for (int i = 0; i < 26; i++) id[i][i] = 1;
        matrix A(26, vector<ll>(26));
        for (int i = 0; i < 26; i++) {
            int L = (i + 1) % 26, R = (i + nums[i]) % 26;
            if (L <= R) {
                for (int j = L; j <= R; j++) {
                    A[j][i] = 1;
                }
            } else {
                for (int j = L; j <= 25; j++) {
                    A[j][i] = 1;
                }
                for (int j = 0; j <= R; j++) {
                    A[j][i] = 1;
                }
            }
        }
        
        vector<ll> cnt(26);
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        matrix At = fpow(A, t);
        // for (int i = 0; i < 26; i++) {
        //     for (int j = 0; j < 26; j++) {
        //         cout << A[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "---\n";
        // for (int i = 0; i < 26; i++) {
        //     for (int j = 0; j < 26; j++) {
        //         cout << At[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ll tmp = 0;
            for (int j = 0; j < 26; j++) {
                tmp = (tmp + 1ll * At[i][j] * cnt[j]) % MOD;
            }
            ans = (ans + tmp) % MOD;
        }
        return ans;
    }
};

