class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> bruh(m);
        iota(bruh.begin(), bruh.end(), 1);
        vector<int> ans;
        for (auto e : queries) {
            int id;
            for (int i = 0; i < m; i++) {
                if (bruh[i] == e) {
                    ans.push_back(i);
                    id = i;
                    break;
                }
            }
            for (int i = id; i >= 1; i--) {
                bruh[i] = bruh[i - 1];
            }
            bruh[0] = e;
        }
        return ans;
    }
};