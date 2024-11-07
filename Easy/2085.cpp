class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> m1, m2;
        int ans = 0;
        for (auto e : words1) m1[e]++;
        for (auto e : words2) m2[e]++;
        for (auto e : m1) { ans += e.second == 1 && m2[e.first] == 1; }
        return ans;
    }
};