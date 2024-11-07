class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        deque<int> de;
        const int M = 1e4;
        vector<bool> ada(M + 1);
        int cur = 0;
        int ans = 0;
        for (auto e : nums) {
            if (!ada[e]) {
                cur += e;
                ada[e] = true;
                de.push_back(e);
            } else {
                while (de.front() != e) {
                    ada[de.front()] = false;
                    cur -= de.front();
                    de.pop_front();
                }
                de.pop_front();
                de.push_back(e);
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};