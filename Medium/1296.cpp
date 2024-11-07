class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        multiset<int> se;
        for (auto e : nums) se.insert(e);
        while (!se.empty()) {
            int cur = *se.begin();
            se.erase(se.begin());
            for (int i = cur + 1; i <= cur + k - 1; i++) {
                if (!se.count(i)) return false;
                se.erase(se.find(i));
            }
        }
        return true;
    }
};