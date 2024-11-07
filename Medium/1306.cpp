class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n);
        queue<int> Q;
        Q.push(start);
        vis[start] = true;
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            if (arr[now] == 0) return true;
            if (now + arr[now] < n) {
                if (!vis[now + arr[now]]) {
                    Q.push(now + arr[now]);
                    vis[now + arr[now]] = true;
                }
            }
            if (now - arr[now] >= 0) {
                if (!vis[now - arr[now]]) {
                    Q.push(now - arr[now]);
                    vis[now - arr[now]] = true;
                }
            }
        }
        return false;
    }
};