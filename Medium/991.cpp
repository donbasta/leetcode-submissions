class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans = 0;
        while (startValue < target) {
            int tmp = startValue;
            int pw = 1;
            while (tmp < target) { tmp <<= 1; pw <<= 1; }
            // cout << tmp << '\n';
            int st = (tmp - target) / pw;
            ans += st;
            startValue -= st;
            startValue <<= 1;
            ans++;
        }
        ans += startValue - target;
        return ans;
    }
};