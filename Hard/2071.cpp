class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());

        auto ok = [&](int cnt) -> bool {
            multiset<int> se;
            for (auto w : workers) se.insert(w);
            int sisa = pills;
            for (int i = cnt - 1; i >= 0; i--) {
                auto it = se.lower_bound(tasks[i]);
                if (it != se.end()) {
                    se.erase(it);
                } else {
                    if (sisa == 0) return false;
                    auto it2 = se.lower_bound(tasks[i] - strength);
                    if (it2 == se.end()) return false;
                    se.erase(it2);
                    sisa--;
                }
            }
            return true;
        };

        int n = tasks.size();
        int l = 1, r = n, ans = 0;;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ok(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};