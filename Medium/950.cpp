class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        deque<int> de;
        for (int i = 0; i < n; i++) {
            de.push_back(i);
        }
        vector<int> ret(n);
        sort(deck.begin(), deck.end());
        int ptr = 0;
        while (!de.empty()) {
            ret[de.front()] = deck[ptr++];
            de.pop_front();
            if (!de.empty()) {
                int x = de.front();
                de.pop_front();
                de.push_back(x);
            }
        }
        return ret;
    }
};