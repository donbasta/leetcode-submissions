class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int cnt = words.size();
        int mx = 1 << cnt;
        vector<int> freq(26);
        for (char l : letters) freq[l - 'a']++;
        int ans = 0;
        for (int i = 1; i < mx; i++) {
            vector<int> countFreq(26);
            for (int j = 0; j < cnt; j++) {
                if (!(i & (1 << j))) continue;
                for (auto c : words[j]) {
                    countFreq[c - 'a']++;
                }
            }
            bool can = true;
            int sc = 0;
            for (int j = 0; j < 26; j++) {
                sc += countFreq[j] * score[j];
                if (countFreq[j] > freq[j]) {
                    can = false;
                    break;
                }
            }
            if (can) {
                ans = max(ans, sc);
            }
        }
        return ans;
    }
};