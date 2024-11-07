class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for (auto e : beans) sum += e;
        int n = beans.size();
        long long tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp = max(tmp, 1ll * beans[i] * (n - i));
        }
        return sum - tmp;
    }
};