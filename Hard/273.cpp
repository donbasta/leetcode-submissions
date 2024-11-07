class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string f[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string h[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string g[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        auto three_digit_part = [&](string s) -> string {
            string ret;
            if (s[0] != '0') ret += (f[s[0] - '0'] + " " + "Hundred ");
            if (s[1] != '0') {
                if (s[1] == '1') {
                    ret += g[stoi(s.substr(1, 2)) - 10];
                    return ret;
                } else {
                    ret += (h[s[1] - '0'] + " ");
                }
            }
            if (s[2] != '0') ret += f[s[2] - '0'];
            while (ret.back() == ' ') ret.pop_back();
            return ret;
        };
        string ret;
        string lol = to_string(num);
        while (lol.size() % 3 != 0) lol = "0" + lol;
        string suf[] = {"Billion", "Million", "Thousand", ""};
        int j = 4 - (lol.size() / 3);
        for (int i = 0; i < lol.size(); i += 3) {
            if (lol.substr(i, 3) == "000") { j++; continue; }
            ret += three_digit_part(lol.substr(i, 3));
            ret += " " + suf[j++];
            ret += " ";
        }
        while (ret.back() == ' ') ret.pop_back();
        return ret;
    }
};