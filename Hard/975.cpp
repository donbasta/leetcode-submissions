class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> n1(n, n), n2(n, n);
        set<pair<int, int>> se;
        se.emplace(arr[n - 1], n - 1);
        for (int i = n - 2; i >= 0; i--) {
            auto ptr = se.lower_bound(make_pair(arr[i], -1));
            if (ptr != se.end()) {
                n1[i] = ptr->second;
            }
            if (ptr != se.end() && ptr->first == arr[i]) {
                n2[i] = ptr->second;
            } else if (ptr != se.begin()) {
                int prv = (--ptr)->first;
                ptr = se.lower_bound(make_pair(prv, -1));
                n2[i] = ptr->second;
            }
            se.emplace(arr[i], i);
        }
        vector<vector<int>> ending(n, vector<int>(2));
        int ret = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (n1[i] == n) {
                ending[i][0] = i;
            } else {
                ending[i][0] = ending[n1[i]][1];
            }
            if (n2[i] == n) {
                ending[i][1] = i;
            } else {
                ending[i][1] = ending[n2[i]][0];
            }
            ret += (ending[i][0] == n - 1);
        }
        return ret;
    }
};