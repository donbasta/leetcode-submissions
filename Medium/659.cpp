class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, multiset<int>> lmao;
        for (auto e : nums) {
            if (lmao.find(e - 1) == lmao.end()) {
                lmao[e].insert(1);
            } else {
                int lenSmallest = *lmao[e - 1].begin();
                lmao[e - 1].erase(lmao[e - 1].begin());
                lmao[e].insert(lenSmallest + 1);
                if (lmao[e - 1].empty()) {
                    lmao.erase(e - 1);
                }
            }
        }
        for (auto e : lmao) {
            if (*(e.second.begin()) < 3) return false;
        }
        return true;
    }
};