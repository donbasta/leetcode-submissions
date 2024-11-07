class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        int g = __gcd(n, k);
        long long ret = 0;

        const function<long long(int, vector<int>&)> f = [&](int x, vector<int>& ve) -> long long {
            long long ret = 0;
            for (auto e : ve) ret += abs(x - e);
            return ret;
        };

        const function<long long(int, int, vector<int>&)> terser = [&](int l, int r, vector<int>& ve) -> long long {
            while (r - l >= 3) {
                int m1 = l + (r - l) / 3;
                int m2 = r - (r - l) / 3;
                long long f1 = f(m1, ve);
                long long f2 = f(m2, ve);
                if (f1 > f2) {
                    l = m1 + 1;
                } else {
                    r = m2;
                }
            }
            long long mn = 1e18;
            for (; l <= r; l++) {
                mn = min(mn, f(l, ve));
            }
            return mn;
        };

        for (int i = 0; i < g; i++) {
            vector<int> tmp;
            for (int j = i; j < n; j += g) {
                tmp.push_back(arr[j]);
            }
            int INF = 1e9;
            ret += terser(0, INF, tmp);
        }

        return ret;
    }
};