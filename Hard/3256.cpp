class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        using ll = long long;
        int m = board.size();
        int n = board[0].size();
  
        vector<vector<pair<int, int>>> row(m);
        for (int i = 0; i < m; i++) {
            vector<pair<int, int>> tmp;
            for (int j = 0; j < n; j++) {
                tmp.emplace_back(board[i][j], j);
            }
            sort(tmp.begin(), tmp.end(), greater<>());
            row[i].push_back(tmp[0]);
            row[i].push_back(tmp[1]);
            row[i].push_back(tmp[2]);
        }

        ll ans = -1e18;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    for (int a = 0; a < 3; a++) {
                        for (int b = 0; b < 3; b++) {
                            for (int c = 0; c < 3; c++) {
                                // if ((a > 0) && (b > 0) && (c > 0)) continue;
                                // set<int> tmp;
                                if ((row[i][a].second == row[j][b].second)) continue;
                                if ((row[i][a].second == row[k][c].second)) continue;
                                if ((row[j][b].second == row[k][c].second)) continue;
                                // tmp.insert(row[i][a].second);
                                // tmp.insert(row[j][b].second);
                                // tmp.insert(row[k][c].second);
                                // if (tmp.size() < 3) continue;
                                ans = max(ans, 1ll * row[i][a].first + row[j][b].first + row[k][c].first);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};