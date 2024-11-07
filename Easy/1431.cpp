class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m1 = *max_element(candies.begin(), candies.end());
        vector<bool> ret;
        for (auto e : candies) {
            if (e + extraCandies >= m1) ret.push_back(true);
            else ret.push_back(false);
        }
        return ret;
    }
};