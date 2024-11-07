struct interval_map {
    int m_valBegin;
    map<int, int> m_map;
    interval_map(int val) : m_valBegin(val) {}

    void assign(int le, int ri, int val) {
        if (le >= ri) {
            return;
        }
        auto itr_left = m_map.upper_bound(le);
        auto itr_right = m_map.upper_bound(ri);
        int keyEnd_val = (*this)[ri];

        m_map.erase(itr_left, itr_right);
        m_map[le] = val;
        if (keyEnd_val != val) {
            m_map[ri] = keyEnd_val;
        }

        auto it = m_map.find(le);
        int prev_value = (it == m_map.begin() ? m_valBegin : (--it)->second);
        if (prev_value == val) {
            m_map.erase(m_map.find(le));
        }
    }

    int const& operator[](int key) {
        auto it = m_map.upper_bound(key);
        if (it == m_map.begin()) {
            return m_valBegin;
        } else {
            return (--it)->second;
        }
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        interval_map LMAO(0);
        sort(buildings.begin(), buildings.end(), [&](auto x, auto y) -> bool {
            return x[2] < y[2];
        });
        for (auto e : buildings) {
            LMAO.assign(e[0], e[1], e[2]);
        }
        vector<vector<int>> res;
        for (auto e : LMAO.m_map) {
            res.push_back({e.first, e.second});
        }
        return res;
    }
};