class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (auto e : arr) {
            cnt[e]++;
        }
        for (auto e : arr) {
            if (e == 0) {
                if (cnt[0] >= 2) return true;
            } else {
                if (cnt.count(2 * e)) return true;
            }
        }
        return false;
    }
};