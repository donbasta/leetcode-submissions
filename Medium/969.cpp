class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        const function<void(int)> revPrefix = [&](int p) -> void {
            for (int i = 0; i < p / 2; i++) {
                swap(arr[i], arr[p - 1 - i]);
            }
        };
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                if (arr[j] == i) {
                    ans.push_back(j + 1);
                    revPrefix(j + 1);
                    break;
                }
            }
            ans.push_back(i);
            revPrefix(i);
        }
        return ans;
    }
};