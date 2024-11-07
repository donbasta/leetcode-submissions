class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n & 1) return {};
        multiset<int> se;
        for (auto e : changed) se.insert(e);
        vector<int> ret;
        while (!se.empty()) {
            int now = *se.begin();
            int doubled = now * 2;
            se.erase(se.find(now));
            if (se.find(doubled) == se.end()) return {};
            ret.push_back(now);
            se.erase(se.find(doubled));
        }
        return ret;
    }
};