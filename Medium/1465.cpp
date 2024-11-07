class Solution {
public:
    int maxArea(int h, int w, vector<int>& H, vector<int>& W) {
        const int MOD = 1e9 + 7;
        sort(H.begin(), H.end());
        sort(W.begin(), W.end());
        int mh = H[0];
        for (int i = 1; i < H.size(); i++) {
            mh = max(mh, H[i] - H[i - 1]);
        }
        mh = max(mh, h - H.back());
        int mw = W[0];
        for (int i = 1; i < W.size(); i++) {
            mw = max(mw, W[i] - W[i - 1]);
        }
        mw = max(mw, w - W.back());
        return (1ll * mh * mw) % MOD;
    }
};