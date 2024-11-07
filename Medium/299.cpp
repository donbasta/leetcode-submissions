class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bull = 0, cow = 0;
        vector<int> c1(10), c2(10);
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) bull++;
            else c1[secret[i] - '0']++, c2[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; i++) {
            cow += min(c1[i], c2[i]);
        }
        string ret;
        ret += to_string(bull);
        ret.push_back('A');
        ret += to_string(cow);
        ret.push_back('B');
        return ret;
    }
};