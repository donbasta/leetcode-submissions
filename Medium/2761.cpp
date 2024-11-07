class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if (n <= 3) return {};
        vector<bool> isPrime(n, true);
        isPrime[1] = false;
        unordered_map<int, bool> ump;
        for (int i = 2; i < n; i++) {
            if (!isPrime[i]) continue;
            ump[i] = true;
            for (int j = i + i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        vector<vector<int>> ret;
        for (auto e : ump) {
            if (e.first * 2 > n) continue;
            if (ump.find(n - e.first) != ump.end()) {
                ret.push_back({e.first, n - e.first});
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};