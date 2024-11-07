class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();

        string S[n];
        int id[n];
        map<vector<int>, int> mp;
        int ord = 0;
        vector<vector<int>> freq(n, vector<int>(10));
        for (int i = 0; i < n; i++) {
            S[i] = to_string(nums[i]);
            reverse(S[i].begin(), S[i].end());
            while (S[i].length() < 7) S[i].push_back('0');
            for (int j = 0; j < 7; j++) {
                freq[i][S[i][j] - '0']++;
            }
            if (mp.find(freq[i]) == mp.end()) mp[freq[i]] = ord++;
            id[i] = mp[freq[i]];
        }

        pair<char, char> ve[4];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    ans++;
                    continue;
                }
                if (id[i] != id[j]) continue;
                int ptr = 0;
                bool ok = true;
                for (int d = 0; d < 7; d++) {
                    if (S[i][d] != S[j][d]) {
                        if (ptr == 4) {
                            ok = false;
                            break;
                        }
                        ve[ptr++] = make_pair(S[i][d], S[j][d]);
                    }
                }
                // cout << i << ' ' << j << ' ' << id[i] << ' ' << id[j] << ' ' << nums[i] << ' ' << nums[j] << ' ' << ans << '\n';
                if (!ok) continue;
                if (ptr == 1 || ptr >= 5) continue;
                else if (ptr == 0) { 
                    ans++; 
                } else if (ptr == 2) {
                    ans++;
                    // if (ve[0].first == ve[1].second && ve[0].second == ve[1].first) {
                    //     ans++;
                    // } else {
                    //     continue;
                    // }
                } else if (ptr == 3) {
                    ans++;
                    // if (ve[0].first == ve[1].second && ve[1].first == ve[2].second && ve[2].first == ve[0].second) {
                    //     ans++;
                    // } else if (ve[0].first == ve[2].second && ve[1].first == ve[0].second && ve[2].first == ve[1].second) {
                    //     ans++;
                    // } else {
                    //     continue;
                    // }
                } else if (ptr == 4) {
                    int x = ve[0].first, y = ve[0].second, pos = -1;
                    // vector<int> rem;
                    for (int k = 1; k < 4; k++) {
                        if (ve[k].first == y && ve[k].second == x && pos == -1) {
                            pos = k;
                            break;
                        } else {
                            // rem.push_back(k);
                        }
                    }
                    if (pos != -1) ans++;
                    // if (pos == -1) continue;
                    // assert (rem.size() == 2);
                    // if (ve[rem[0]].first == ve[rem[1]].second && ve[rem[0]].second == ve[rem[1]].first) {
                    //     ans++;
                    // }
                }
            }
        }
        return ans;
    }
};