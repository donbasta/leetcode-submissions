class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        string haha(n, ' ');
        int i = 0;
        for (auto e : indices) {
            haha[e] = s[i++];
        }
        return haha;
    }
};