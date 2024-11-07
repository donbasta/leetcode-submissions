const int INF = 2e9;

class TopVotedCandidate {
public:
    vector<int> mp;
    vector<pair<int, int>> ve;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        // memset(mp, 0, sizeof(mp));
        int n = persons.size();
        mp.resize(n);
        int mx = 0, id = -1;
        for (int i = 0; i < n; i++) {
            int cur = mp[persons[i]];
            mp[persons[i]] = cur + 1;
            if (cur + 1 >= mx) {
                mx = cur + 1;
                id = persons[i];
            }
            ve.emplace_back(times[i], id);
        }
    }

    int q(int t) {
        int idx = upper_bound(ve.begin(), ve.end(), make_pair(t, INF)) - ve.begin();
        assert (idx > 0);
        return ve[idx - 1].second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */