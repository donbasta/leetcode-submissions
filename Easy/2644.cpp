class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(), divisors.end());
        int mx = -1;
        int val = -1;
        for (auto d : divisors) {
            int tmp = 0;
            for (auto n : nums) tmp += (n % d == 0);
            if (tmp > mx) {
                mx = tmp;
                val = d;
            }
        }
        return val;
    }
};