class Solution {
public:
    int maxVowels(string s, int k) {
        const function<bool(char)> isVowel = [&](char c) -> bool {
            string check = "aiueo";
            for (auto e : check) if (c == e) return true;
            return false; 
        };
        int tmp = 0;
        int ans = 0;
        for (int i = 0; i < k - 1; i++) {
            tmp += isVowel(s[i]);
        }
        int n = s.length();
        for (int i = k - 1; i < n; i++) {
            tmp += isVowel(s[i]);
            ans = max(ans, tmp);
            tmp -= isVowel(s[i - k + 1]);
        }
        return ans;
    }
};