class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        vector<int> lmao;
        int n = aliceValues.size();
        int B = 0, L = 0;
        for (int i = 0; i < n; i++) {
            lmao.push_back(aliceValues[i] + bobValues[i]);
            B += bobValues[i];
        }
        sort(lmao.begin(), lmao.end(), greater<int>());
        for (int i = 0; i < n; i += 2) {
            L += lmao[i];
        }
        int ret;
        if (L > B) ret = 1;
        else if (L == B) ret = 0;
        else ret = -1;
        return ret;
    }
};