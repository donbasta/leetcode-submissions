class Solution {
public:
    int numSteps(string s) {
        int ret = 0;
        while (s.size() > 1) {
            if (s.back() == '1') {
                int bl = 0;
                while (!s.empty() && s.back() == '1') {
                    s.pop_back();
                    bl++;
                }
                if (s.empty()) s.push_back('1');
                else {
                    s.back() = '1';
                }
                ret += (bl + 1);
            } else {
                s.pop_back();
                ret++;
            }
        }
        return ret;
    }
};