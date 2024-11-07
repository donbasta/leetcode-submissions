class Solution {
public:
    string countOfAtoms(string formula) {
        vector<map<string, int>> ve(1);
        string buf_name;
        int buf_count = -1;

        auto is_digit = [&](char c) -> bool { return c >= '0' && c <= '9'; };
        auto is_lower = [&](char c) -> bool { return c >= 'a' && c <= 'z'; };
        auto is_upper = [&](char c) -> bool { return c >= 'A' && c <= 'Z'; };
        auto check_add = [&]() {
            if (!buf_name.empty()) {
                if (buf_count == -1) {
                    ve.back()[buf_name]++;
                } else {
                    ve.back()[buf_name] += buf_count;
                }
                buf_count = -1;
                buf_name.clear();
            }
        };

        bool unproc = false;
        for (auto c : formula) {
            if (unproc && !is_digit(c)) {
                int mul = buf_count;
                if (mul == -1) mul = 1;
                for (auto e : ve.back()) {
                    ve[ve.size() - 2][e.first] += e.second * mul;
                }
                ve.pop_back();
                unproc = false;
                buf_count = -1;
            }

            if (c == '(') {
                check_add();
                map<string, int> tmp;
                ve.push_back(tmp);
            } else if (c == ')') {
                check_add();
                unproc = true;
            } else if (is_digit(c)) {
                if (buf_count == -1) {
                    buf_count = 0;
                }
                buf_count = buf_count * 10 + (c - '0');
            } else if (is_upper(c)) {
                check_add();
                buf_name += c;
            } else { //lowercase
                buf_name += c;
            }
        }
        check_add();
        if (unproc) {
            int mul = buf_count;
            if (mul == -1) mul = 1;
            for (auto e : ve.back()) {
                ve[ve.size() - 2][e.first] += e.second * mul;
            }
            ve.pop_back();
            unproc = false;
        }

        string res;
        for (auto e : ve[0]) {
            res += e.first;
            if (e.second > 1) {
                res += to_string(e.second);
            }
        }
        return res;
    }
};