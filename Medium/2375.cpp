class Solution {
public:
    string smallestNumber(string pattern) {
        pattern = "I" + pattern;
        int n = pattern.length(); //we use 1 to n
        string ret(n, '0');
        int last = n;
        int cur = n;
        while (last > 0) {
            int tmp = -1;
            for (int i = last - 1; i >= 0; i--) {
                if (pattern[i] == 'I') {
                    tmp = i;
                    break;
                }
            }
            for (int i = tmp; i < last; i++) {
                ret[i] = (char)(cur + '0');
                cur--;
            }
            last = tmp;
        }
        return ret;
    }
};