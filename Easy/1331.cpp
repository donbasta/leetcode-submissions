class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> comp = arr;
        sort(comp.begin(), comp.end());
        comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
        map<int, int> mp;
        for (int i = 0; i < comp.size(); i++) {
            mp[comp[i]] = i + 1;
        }
        for (auto& e : arr) {
            e = mp[e];
        }
        return arr;
    }
};