class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; i++) {
            string t = to_string(i);
            int tmp = 0;
            for (auto c : t) tmp += (c - '0');
            ans += (tmp % 2 == 0);
        }
        return ans;
    }
};