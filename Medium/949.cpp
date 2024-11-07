class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        const function<bool(vector<int>)> is_valid = [&](vector<int> ve) -> bool {
            int hour = 10 * ve[0] + ve[1];
            int min = 10 * ve[2] + ve[3];
            return ((hour <= 23) && (min <= 59));
        };
        vector<int> ve;
        sort(arr.begin(), arr.end());
        do {
            // for (auto e : arr) cout << e << ' ';
            // cout << is_valid(arr) << '\n';
            if (is_valid(arr)) {
                ve = max(ve, arr);
            }
        } while (next_permutation(arr.begin(), arr.end()));
        if (ve.empty()) return "";
        string ret;
        ret.push_back((char)(ve[0] + '0'));
        ret.push_back((char)(ve[1] + '0'));
        ret.push_back(':');
        ret.push_back((char)(ve[2] + '0'));
        ret.push_back((char)(ve[3] + '0'));
        return ret;
    }
};