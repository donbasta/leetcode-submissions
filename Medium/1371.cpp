class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int pos[32], pref[n];
        pos[0] = -1;
        int cur = 0;

        auto get_id = [&](char c) -> int {
            int ptr = 0;
            for (auto cc : "aeiou") {
                if (cc == c) {
                    return ptr;
                }
                ptr++;
            }
            return -1;
        };

        for (int i = 0; i < n; i++) {
            int id = get_id(s[i]);
            if (id != -1) {
                cur ^= (1 << id);   
            }
            pos[cur] = i;
            pref[i] = cur;
        }
        cur = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pos[cur] - i + 1);
            cur = pref[i];
        }
        return ans;
    }
};