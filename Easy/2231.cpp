class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> indices_odd, indices_even;
        string odd, even;
        for (int i = 0; i < s.size(); i++) {
            int dig = s[i] - '0';
            if (dig & 1) {
                indices_odd.push_back(i);
                odd.push_back(s[i]);
            } else {
                indices_even.push_back(i);
                even.push_back(s[i]);
            }
        }
        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end(), greater<>());
        for (int i = 0; i < indices_odd.size(); i++) {
            s[indices_odd[i]] = odd[i];
        }
        for (int i = 0; i < indices_even.size(); i++) {
            s[indices_even[i]] = even[i];
        }
        return stoi(s);
    }
};