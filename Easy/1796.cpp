class Solution {
public:
    int secondHighest(string s) {
        set<int> se;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                se.insert(c - '0');
            }
        }
        if (se.size() <= 1) return -1;
        auto ptr = se.end();
        --ptr, --ptr;
        return *ptr;
    }
};