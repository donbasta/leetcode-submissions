class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char, bool> mp;
        for (auto c : word) mp[c] = true;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            char low = (char)(i + 'a');
            char up = (char)(i + 'A');
            if (mp.count(low) && mp.count(up)) ans++;
        }
        return ans;
    }
};