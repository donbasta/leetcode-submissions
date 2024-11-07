class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) -> bool {
            int na = __builtin_popcount(a), nb = __builtin_popcount(b);
            if (na == nb) return a < b;
            return na < nb;
        });
        return arr;
    }
};