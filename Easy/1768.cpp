class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int w1 = word1.length(), w2 = word2.length();
        string ret;
        for (int i = 0; i < max(w1, w2); i++) {
            if (i < w1) ret.push_back(word1[i]);
            if (i < w2) ret.push_back(word2[i]);
        }
        return ret;
    }
};