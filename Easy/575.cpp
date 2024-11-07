class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> se;
        for (auto c : candyType) se.insert(c);
        int n = candyType.size();
        return min((int)se.size(), n / 2);
    }
};