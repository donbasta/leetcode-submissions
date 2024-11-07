class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        vector<int> ve;
        for (auto e : asteroids) {
            if (e > 0) ve.push_back(e);
            else {
                bool ins = true;
                while (!ve.empty()) {
                    int now = ve.back();
                    if (abs(now) < abs(e)) {
                        ve.pop_back();
                    } else if (abs(now) == abs(e)) {
                        ve.pop_back();
                        ins = false;
                        break;
                    } else {
                        ins = false;
                        break;
                    }
                }
                if (ve.empty() && ins) {
                    ans.push_back(e);
                }
            }
        }
        for (auto e : ve) {
            ans.push_back(e);
        }
        return ans;
    }
};