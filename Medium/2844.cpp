class Solution {
public:
    int minimumOperations(string num) {
        vector<string> last_two = {"00", "25", "50", "75"};
        int n = num.length();
        bool ada_nol = false;
        for (auto c : num) if (c == '0') ada_nol = true;
        int ans = n;
        if (ada_nol) ans = min(ans, n - 1);
        for (auto s : last_two) {
            bool found = false;
            for (int i = n - 1; i >= 0; i--) {
                if ((!found) && (num[i] == s[1])) {
                    found = true;
                } else if (found && (num[i] == s[0])) {
                    ans = min(ans, n - i - 2);
                    break;
                }
            }
        }
        return ans;
    }
};