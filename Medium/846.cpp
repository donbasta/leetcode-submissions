class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int sz = hand.size();
        if (sz % groupSize != 0) return false;
        multiset<int> se;
        for (auto h : hand) se.insert(h);
        while (!se.empty()) {
            int start = *se.begin();
            for (int i = start; i <= start + groupSize - 1; i++) {
                if (!se.count(i)) return false;
                se.erase(se.find(i));
            }
        }
        return true;
    }
};