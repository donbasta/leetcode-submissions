class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> hehe;
        for (auto str : strs) {
            vector<int> cnt(26);
            for (auto c : str) {
                cnt[c - 'a']++;
            }
            hehe[cnt].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto e : hehe) {
            ans.push_back(e.second);
        }
        return ans;
    }
};