class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        multiset<int> s1, s2;
        for (auto e : arr) {
            if (e >= 0) s1.insert(e);
            else s2.insert(-e);
        }
        if (s1.size() & 1) return false;
        if (s2.size() & 1) return false;
        while (!s1.empty()) {
            int now = *s1.begin();
            int doubled = now * 2;
            s1.erase(s1.find(now));
            if (s1.find(doubled) == s1.end()) return false;
            s1.erase(s1.find(doubled));
        }
        while (!s2.empty()) {
            int now = *s2.begin();
            int doubled = now * 2;
            s2.erase(s2.find(now));
            if (s2.find(doubled) == s2.end()) return false;
            s2.erase(s2.find(doubled));
        }
        return true;
    }
};