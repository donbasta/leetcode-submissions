class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tot = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<>());
        int tot_cap = 0;
        int n = capacity.size();
        for (int i = 0; i < n; i++) {
            tot_cap += capacity[i];
            if (tot_cap >= tot) return (i + 1);
        }
        return n;
    }
};