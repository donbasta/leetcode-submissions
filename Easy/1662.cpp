class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string sa, sb;
        for (auto c : word1) sa += c;
        for (auto c : word2) sb += c;
        return sa == sb;
    }
};