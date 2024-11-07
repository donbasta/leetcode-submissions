class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ret, rem;
        map<int, int> pos, cnt;
        for (int i = 0; i < (int)arr2.size(); i++) pos[arr2[i]] = i;
        for (int i = 0; i < (int)arr1.size(); i++) {
            if (pos.count(arr1[i])) cnt[arr1[i]]++;
            else rem.push_back(arr1[i]);
        }
        sort(rem.begin(), rem.end());
        for (int i = 0; i < (int)arr2.size(); i++) {
            for (int j = 0; j < cnt[arr2[i]]; j++) {
                ret.push_back(arr2[i]);
            }
        }
        for (auto r : rem) ret.push_back(r);
        return ret;
    }
};