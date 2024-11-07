class Solution {
public:
    int compress(vector<char>& chars) {
        char cur = '\n';
        int cnt = 0;
        int last = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] != cur) {
                if (cur != '\n') {
                    chars[last] = cur;
                    if (cnt > 1) {
                        string lmao = to_string(cnt);
                        for (int j = last + 1; j <= last + lmao.size(); j++) {
                            chars[j] = lmao[j - last - 1];
                        }
                        last = last + lmao.size() + 1;
                    } else {
                        last = last + 1;
                    }
                }
                cur = chars[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        chars[last] = cur;
        if (cnt > 1) {
            string lmao = to_string(cnt);
            for (int j = last + 1; j <= last + lmao.size(); j++) {
                chars[j] = lmao[j - last - 1];
            }
            last = last + lmao.size() + 1;
        } else {
            last = last + 1;
        }
        while (chars.size() > last) chars.pop_back();
        return last; 
    }
};