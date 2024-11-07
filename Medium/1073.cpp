class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();
        vector<int> carry(max(m, n) + 5), ret(max(m, n));
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        for (int i = 0; i < min(m, n); i++) {
            int sum = (arr1[i] + arr2[i] + carry[i]);
            ret[i] = sum % 2;
            int tmp = sum / 2;
            carry[i + 2] += tmp;
            carry[i + 1] += tmp;
        }
        for (int i = min(m, n); i < max(m, n); i++) {
            int sum = carry[i];
            if (m < n) {
                sum += arr2[i];
            } else {
                sum += arr1[i];
            }
            ret[i] = sum % 2;
            int tmp = sum / 2;
            carry[i + 2] += tmp;
            carry[i + 1] += tmp;
        }
        int it = max(m, n);
        while (carry[it] > 0) {
            // cout << carry[it] << ' ' << it << '\n';
            while (carry.size() < it + 3) carry.push_back(0);
            int kur = min(carry[it] / 2, carry[it + 1]);
            carry[it] -= 2 * kur;
            carry[it + 1] -= kur;
            int sum = (carry[it]);
            ret.push_back(sum % 2);
            int tmp = sum / 2;
            carry[it + 2] += tmp;
            carry[it + 1] += tmp;
            it++;
        }
        while (!ret.empty() && ret.back() == 0) ret.pop_back();
        if (ret.empty()) ret.push_back(0);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};