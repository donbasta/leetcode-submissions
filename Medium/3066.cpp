class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> se;
        for (auto e : nums) se.insert(e);
        int turn = 0;
        while (*se.begin() < 1ll * k) {
            long long a = *se.begin();
            se.erase(se.begin());
            long long b = *se.begin();
            se.erase(se.begin());
            se.insert(a * 2 + b);
            turn++;
        }
        return turn;
    }
};