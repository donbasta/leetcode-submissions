class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        set<pair<int, int>> se;
        se.emplace(arr.back(), -(n - 1));
        for (int i = n - 2; i >= 0; i--) {
            auto itr = se.lower_bound(make_pair(arr[i], INT_MIN));
            if (itr != se.begin()) {
                --itr;
                swap(arr[i], arr[-itr->second]);
                return arr;
            }
            se.emplace(arr[i], -i);
        }
        return arr;
    }
};