class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ve = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> ans;
        if (digits.length() == 0) return ans;

        const function<void(int, string&)> rec = [&](int idx, string& lol) -> void {
            if (idx == digits.length()) {
                ans.push_back(lol);
                return;
            }
            for (auto c : ve[digits[idx] - '0']) {
                lol.push_back(c);
                rec(idx + 1, lol);
                lol.pop_back();
            }
        };

        string tmp;
        rec(0, tmp);
        return ans;
    }
};