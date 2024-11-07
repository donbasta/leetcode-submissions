class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int sz = arr.size();
        map<int, int> mp;
        set<int> se;
        se.insert(arr.back());
        for (int i = 0; i < sz - 1; i++) {
            se.insert(arr[i]);
            mp[arr[i]] = arr[i + 1];
        }
        for (auto ve : pieces) {
            int len = ve.size();
            if (!se.count(ve.back())) return false;
            for (int i = 0; i < len - 1; i++) {
                if (!mp.count(ve[i])) return false;
                if (mp[ve[i]] != ve[i + 1]) return false;
                if (!se.count(ve[i])) return false;
            }
        }
        return true;
    }
};