class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> se;
        for (auto c : s) se.insert(c);
        return se.size();
    }
};