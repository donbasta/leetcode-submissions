class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> tmp;
        int cur = nums[0];
        int n = nums.size();
        const function<int(int, int)> lcm = [&](int a, int b) {
            return a * (b / __gcd(a, b));
        };
        for (int i = 1; i < n; i++) {
            if (__gcd(cur, nums[i]) == 1) {
                tmp.push_back(cur);
                cur = nums[i];
            } else {
                cur = lcm(cur, nums[i]);
                while (!tmp.empty() && __gcd(tmp.back(), cur) > 1) {
                    cur = lcm(cur, tmp.back());
                    tmp.pop_back();
                }
            }
        }
        tmp.push_back(cur);
        return tmp;
    }
};