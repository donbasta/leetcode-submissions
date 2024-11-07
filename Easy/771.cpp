class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> se;
        for (auto c : jewels) se.insert(c);
        int ans = 0;
        for (auto c : stones) ans += se.count(c);
        return ans;
    }
};