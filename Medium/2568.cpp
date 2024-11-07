class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int> se;
        for (auto e : nums) se.insert(e);
        int i = 1;
        while (true) {
            if (!se.count(i)) {
                return i;
            }
            i *= 2;
        }
        return -1;
    }
};