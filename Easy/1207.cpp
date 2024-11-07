class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto e : arr) cnt[e]++;
        set<int> se;
        for (auto e : cnt) se.insert(e.second);
        return se.size() == cnt.size();
    }
};