class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;

        int n = words.size();
        int start = 0;
        int cur_tot = 0;
        int j = start;
        const function<string(int, int, bool)> construct = [&](int l, int r, bool left_justified) -> string {
            if (left_justified) {
                string ret;
                for (int i = l; i <= r; i++) {
                    for (auto c : words[i]) ret.push_back(c);
                    if (i < r) ret.push_back(' ');
                }
                while (ret.length() < maxWidth) ret.push_back(' ');
                return ret;
            }
            if (l == r) {
                string ret;
                for (auto c : words[l]) ret.push_back(c);
                while (ret.length() < maxWidth) ret.push_back(' ');
                return ret;
            }
            int tot = 0;
            for (int i = l; i <= r; i++) {
                tot += words[i].length();
            }
            int cnt_gaps = (r - l);
            int len_gap = (maxWidth - tot) / cnt_gaps;
            int add_one_more = (maxWidth - tot) % cnt_gaps;
            string ret;
            for (int i = l; i <= r; i++) {
                for (auto c : words[i]) ret.push_back(c);
                if (i < r) {
                    for (int t = 0; t < len_gap; t++) ret.push_back(' ');
                    if (i < l + add_one_more) ret.push_back(' ');
                }
            }
            return ret;
        };
        while (start < n) {
            while (j < n && cur_tot + (words[j].length()) + (j - start) <= maxWidth) {
                cur_tot += words[j].length();
                j++;
            }
            bool left_justified = false;
            if (j == n) {
                left_justified = true;
            }
            ret.push_back(construct(start, j - 1, left_justified));
            start = j;
            cur_tot = 0;
        }
        return ret;
    }
};