class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> beau;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int j = i;
            int sum = 0;
            while (j < n && sum < k) {
                sum += (s[j] == '1');
                j++;
            }
            if (sum < k) {
                break;
            }
            beau.push_back(s.substr(i, j - i));
        }
        if (beau.empty()) {
            return "";
        }
        int len = INT_MAX;
        for (auto b : beau) {
            len = min(len, (int)b.length());
        }
        string ret = "";
        for (auto b : beau) {
            if ((int)b.length() == len) {
                if (ret == "") ret = b;
                else ret = min(ret, b);
            } 
        }
        return ret;
    }
};