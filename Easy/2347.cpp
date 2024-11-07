class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> cs(4), cf(13);
        for (auto s : suits) cs[s - 'a']++;
        for (auto s : ranks) cf[s - 1]++;
        if (*max_element(cs.begin(), cs.end()) == 5) return "Flush";
        if (*max_element(cf.begin(), cf.end()) >= 3) return "Three of a Kind";
        if (*max_element(cf.begin(), cf.end()) == 2) return "Pair";
        return "High Card";
    }
};