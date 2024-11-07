class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> c1(26), c2(26);
        for (auto c : word1) c1[c - 'a']++;
        for (auto c : word2) c2[c - 'a']++;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (c1[i] == 0 || c2[j] == 0) continue;
                c1[i]--, c1[j]++;
                c2[j]--, c2[i]++;
                int u1 = 0, u2 = 0;
                for (int k = 0; k < 26; k++) {
                    u1 += c1[k] > 0;
                    u2 += c2[k] > 0;
                }
                if (u1 == u2) return true;
                c1[i]++, c1[j]--;
                c2[j]++, c2[i]--;
            }
        }
        return false;
    }
};