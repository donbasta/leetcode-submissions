class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mp;
        for (auto str : arr) mp[str]++;
        vector<string> ve;
        for (auto str : arr) {
            if (mp[str] == 1) ve.push_back(str);
        }
        if ((int)ve.size() < k) return "";
        return ve[k - 1];
    }
};