class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<int, int> mp;
        mp[0] = 0;
        mp[INT_MAX] = 0;
        multiset<int> heights;
        heights.insert(0);
        heights.insert(0);
        vector<int> ans;
        for (auto p : positions) {
            auto p1 = mp.upper_bound(p[0]);
            --p1;
            auto o1 = *p1;
            auto p2 = mp.lower_bound(p[0] + p[1]);
            --p2;
            auto o2 = *p2;
            auto itr = p1;
            int mx = 0;
            vector<pair<int, int>> del;
            bool left = false, right = false;
            if (p1->first < p[0]) {
                left = true;
            }
            if ((++p2)->first > p[0] + p[1]) {
                right = true;
            }
            while (true) {
                del.emplace_back(itr->first, itr->second);
                mx = max(mx, itr->second);
                if (*itr == o2) break;
                ++itr;
            }
            for (auto d : del) {
                mp.erase(d.first);
                heights.erase(heights.find(d.second));
            }
            mp[p[0]] = mx + p[1];
            heights.insert(mx + p[1]);
            if (left) {
                mp[o1.first] = o1.second;
                heights.insert(o1.second);
            }
            if (right) {
                mp[p[0] + p[1]] = o2.second;
                heights.insert(o2.second);
            }
            ans.push_back(*heights.rbegin());
        }
        return ans;
    }
};