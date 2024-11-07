class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        int topk = sz / 20;
        int tot = 0;
        for (int i = topk; i <= sz - topk - 1; i++) {
            tot += arr[i];
        }
        return (double)(tot) / (sz - 2 * topk);
    }
};