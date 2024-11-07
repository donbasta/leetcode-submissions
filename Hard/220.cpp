class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> se, diff;

        const function<void(int)> add = [&](int val) -> void {
            if (se.empty()) {
                se.insert(val);
                return;
            }
            auto lul = se.lower_bound(val);
            if (lul == se.begin()) {
                diff.insert(*se.begin() - val);
            } else if (lul == se.end()) {
                diff.insert(val - *(--se.end()));
            } else {
                int atas = *lul;
                int bawah = *(--lul);
                diff.erase(diff.find(atas - bawah));
                diff.insert(atas - val);
                diff.insert(val - bawah);
            }
            se.insert(val);
        };

        const function<void(int)> rem = [&](int val) -> void {
            auto lul = se.lower_bound(val);
            if (lul == se.begin()) {
                diff.erase(diff.find(*(++lul) - val));
            } else if (lul == (--se.end())) {
                diff.erase(diff.find(val - *(--lul)));
            } else {
                int atas = *(++lul);
                --lul;
                int bawah = *(--lul);
                diff.erase(diff.find(atas - val));
                diff.erase(diff.find(val - bawah));
                diff.insert(atas - bawah);
            }
            se.erase(se.find(val));
        };

        int n = nums.size();
        for (int i = 0; i <= min(n - 1, indexDiff); i++) {
            add(nums[i]);
        }
        
        for (int i = min(n, indexDiff + 1); i <= n; i++) {
            if (*diff.begin() <= valueDiff) {
                return true;
            }
            if (i >= indexDiff + 1) {
                rem(nums[i - indexDiff - 1]);
            }
            if (i < n) {
                add(nums[i]);
            }
        }
        return false;
    }
};