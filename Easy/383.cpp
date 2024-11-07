class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26);
        for (auto c : magazine) cnt[c - 'a']++;
        for (auto c : ransomNote) cnt[c - 'a']--;
        return *min_element(cnt.begin(), cnt.end()) >= 0;
    }
};