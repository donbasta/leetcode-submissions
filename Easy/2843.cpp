class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string t = to_string(i);
            int len = t.length();
            if (len & 1) continue;
            int tmp = 0;
            for (int j = 0; j < (len / 2); j++) {
                tmp += (t[j] - '0');
            }
            for (int j = (len / 2); j < len; j++) {
                tmp -= (t[j] - '0');
            }
            ans += (tmp == 0);
        }
        return ans;
    }
};