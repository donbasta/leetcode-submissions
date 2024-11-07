class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<>());
        int ans = 0;
        int n3 = piles.size();
        int n = n3 / 3;
        for (int i = 1; i <= 2 * n - 1; i += 2) ans += piles[i];
        return ans;
    }
};