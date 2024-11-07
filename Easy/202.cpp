class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> ump;
        int cur = n;
        while (ump.find(cur) == ump.end()) {
            ump[cur] = true;
            int tmp = 0;
            while (cur > 0) {
                int dig = cur % 10;
                tmp += dig * dig;
                cur /= 10;
            }
            if (tmp == 1) return true;
            cur = tmp;
        }
        return false;
    }
};