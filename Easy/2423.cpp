class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26);
        for (auto c : word) {
            cnt[c - 'a']++;
        }
        vector<int> freq;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                freq.push_back(cnt[i]);
            }
        }
        if (freq.size() == 1) return true;
        sort(freq.begin(), freq.end());
        int a = freq.size();
        bool ca = ((freq[0] == freq[a - 2]) && (freq[a - 1] == freq[0] + 1));
        bool cb = ((freq[1] == freq[a - 1]) && (freq[0] == 1));
        return ca || cb;
    }
};