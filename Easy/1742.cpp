class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> cnt(50);
        auto sumdigit = [&](int x) -> int {
            int ret = 0;
            while (x) {
                ret += x % 10;
                x /= 10;
            }
            return ret;
        };
        for (int i = lowLimit; i <= highLimit; i++) {
            cnt[sumdigit(i)]++;
        }
        return *max_element(cnt.begin(), cnt.end());
    }
};