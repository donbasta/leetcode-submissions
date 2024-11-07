class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int hehe = 0;
        for (int i = 0; i < n; i += 2) {
            hehe ^= encoded[i];
        }
        for (int i = 1; i <= n + 1; i++) {
            hehe ^= i;
        }
        // now, hehe = perm[n - 1]
        vector<int> perm(n + 1);
        perm[n] = hehe;
        for (int i = n - 1; i >= 0; i--) {
            perm[i] = encoded[i] ^ perm[i + 1];
        }
        return perm;
    }
};