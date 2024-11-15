class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int med = arr[(n - 1) / 2];
        sort(arr.begin(), arr.end(), [&](int x, int y) -> bool {
            if (abs(x - med) == abs(y - med)) {
                return x > y;
            }
            return abs(x - med) > abs(y - med);
        });
        arr.resize(k);
        return arr;
    }
};