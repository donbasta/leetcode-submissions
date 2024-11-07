class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> m1, m2;
        set<int> se;
        for (auto e : basket1) {
            m1[e]++;
            se.insert(e);
        }
        for (auto e : basket2) {
            m2[e]++;
            se.insert(e);
        }
        vector<long long> dari;
        for (auto e : se) {
            int a = m1[e], b = m2[e];
            if ((a + b) & 1) return -1;
            int cnt = abs(a - b) / 2;
            for (int i = 0; i < cnt; i++) dari.push_back(e);
        }
        int smallest = *se.begin();
        long long ans = 0;
        int n = dari.size();
        // for (auto e : dari) {
        //     cout << e << ' ';
        // }
        
        assert(n % 2 == 0);
        for (int i = 0; i < n / 2; i++) {
            long long bruh = 1LL * smallest * 2;
            ans += min(bruh, dari[i]);
        }
        // long long bruh = 1LL * smallest * dari.size();
        // ans = min(ans, bruh);
        return ans;
    }
};