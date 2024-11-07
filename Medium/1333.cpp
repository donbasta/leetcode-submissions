class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int, int>> ve;
        for (auto r : restaurants) {
            bool ok = true;
            if (veganFriendly) ok &= r[2] == 1;
            ok &= r[3] <= maxPrice;
            ok &= r[4] <= maxDistance;
            if (ok) {
                ve.emplace_back(r[1], r[0]);
            }
        }
        sort(ve.begin(), ve.end(), greater<>());
        vector<int> ret;
        for (auto v : ve) {
            ret.push_back(v.second);
        }
        return ret;
    }
};