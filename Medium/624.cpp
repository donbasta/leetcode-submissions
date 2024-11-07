class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<int> ms;
        for (auto a : arrays) {
            ms.insert(a.back());
        }
        int ans = 0;
        for (auto a : arrays) {
            ms.erase(ms.find(a.back()));
            ans = max(ans, abs(a[0] - *ms.rbegin()));
            ms.insert(a.back());
        }
        return ans;
    }
};