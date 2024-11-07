class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int a = to_string(low).length(), b = to_string(high).length();
        vector<int> tmp;
        for (int i = a; i <= b; i++) {
            for (int j = 1; j <= 10 - i; j++) {
                string lol(i, '\0');
                iota(lol.begin(), lol.end(), (char)(j + '0'));
                tmp.push_back(stoi(lol));
            }
        }
        int sz = tmp.size();
        int i = 0, j = sz - 1;
        while (i < sz && tmp[i] < low) i++;
        while (j >= 0 && tmp[j] > high) j--;
        return vector<int>(tmp.begin() + i, tmp.begin() + j + 1);
    }
};