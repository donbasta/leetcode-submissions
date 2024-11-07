class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> hehe;
        for (auto g : gifts) hehe.push(g);
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            int cur = hehe.top();
            hehe.pop();
            hehe.push(floor(sqrt(cur)));
        }
        while (!hehe.empty()) {
            ans += hehe.top();
            hehe.pop();
        }
        return ans;
    }
};