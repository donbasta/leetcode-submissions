class Solution {
public:
    string entityParser(string text) {
        int n = text.size();
        int itr = 0;
        string ans;
        while (itr < n) {
            if (text[itr] == '&') {
                char c = '\0';
                if (itr <= n - 6 && text.substr(itr, 6) == "&quot;") {
                    c = '"';
                    itr += 6;
                } else if (itr <= n - 4 && text.substr(itr, 4) == "&gt;") {
                    c = '>';
                    itr += 4;
                } else if (itr <= n - 4 && text.substr(itr, 4) == "&lt;") {
                    c = '<';
                    itr += 4;
                } else if (itr <= n - 7 && text.substr(itr, 7) == "&frasl;") {
                    c = '/';
                    itr += 7;
                } else if (itr <= n - 6 && text.substr(itr, 6) == "&apos;") {
                    c = '\'';
                    itr += 6;
                } else if (itr <= n - 5 && text.substr(itr, 5) == "&amp;") {
                    c = '&';
                    itr += 5;
                } else {
                    c = text[itr];
                    itr++;
                }
                ans.push_back(c);
            } else {
                ans.push_back(text[itr]);
                itr++;
            }
        }
        return ans;
    }
};