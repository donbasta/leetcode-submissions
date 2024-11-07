class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        long long ans;
        vector<int> cnt(10);
        if (num > 0) {
            string s = to_string(num);
            int start;
            for (auto c : s) cnt[c - '0']++;
            for (int i = 1; i < 10; i++) {
                if (cnt[i] > 0) {
                    start = i;
                    cnt[i]--;
                    break;
                }
            }
            string ret;
            ret.push_back((char)(start + '0'));
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < cnt[i]; j++) {
                    ret.push_back((char)(i + '0'));
                }
            }
            ans = stoll(ret);
        } else {
            string s = to_string(abs(num));
            for (auto c : s) cnt[c - '0']++;
            string ret;
            for (int i = 9; i >= 0; i--) {
                for (int j = 0; j < cnt[i]; j++) {
                    ret.push_back((char)(i + '0'));
                }
            }
            ans = stoll(ret);
            ans = -ans;
        }
        return ans;
    }
};