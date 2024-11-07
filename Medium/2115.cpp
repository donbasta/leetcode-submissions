class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, vector<string>> from;
        map<string, int> in;
        map<string, bool> ok;
        int n = recipes.size();
        for (int i = 0; i < n; i++) {
            for (auto e : ingredients[i]) {
                from[e].push_back(recipes[i]);
                in[recipes[i]]++;
            }
        }
        queue<string> Q;
        for (auto e : supplies) Q.push(e);
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (auto c : from[now]) {
                in[c]--;
                if (in[c] == 0) {
                    ok[c] = true;
                    Q.push(c);
                }
            }
        }
        vector<string> ans;
        for (auto e : ok) {
            ans.push_back(e.first);
        }
        return ans;
    }
};