class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> last;
        int n = cards.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (last.count(cards[i])) {
                ans = min(ans, i - last[cards[i]] + 1);
            }
            last[cards[i]] = i;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};