class Solution {
public:
    int maxScore(vector<int>& nums) {
        long long tot = 0;
        vector<int> neg;
        int len = 0;
        for (auto e : nums) {
            if (e >= 0) {
                tot += e;
                len++;
            }
            else neg.push_back(e);
        }
        if (tot == 0) return 0;
        sort(neg.begin(), neg.end(), greater<>());
        for (auto e : neg) {
            if (tot + e > 0) {
                tot += e, len++;
            } else {
                break;
            }
        }
        return len;
    }
};