class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string acc;
        for (auto w : words) acc.push_back(w[0]);
        return acc == s;
    }
};