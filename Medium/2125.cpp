class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ve;
        for (auto e : bank) {
            int tmp = 0;
            for (auto c : e) tmp += c == '1';
            if (tmp > 0) ve.push_back(tmp);
        }
        int ans = 0;
        for (int i = 1; i < ve.size(); i++) {
            ans += ve[i] * ve[i - 1];
        }
        return ans;
    }
};