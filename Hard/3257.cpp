class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
       using ll = long long;
       int m = board.size();
       int n = board[0].size();
       ll ret = -1e18;
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

       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
                if (j != row[i][0].second && j != row[i][1].second && j != row[i][2].second) continue;
               int cur = board[i][j];
               vector<vector<pair<ll, int>>> tmp(m, vector<pair<ll, int>>(2));
               vector<vector<pair<int, int>>> col(n);
               vector<vector<int>> best(n);
               for (int k = 0; k < m; k++) {
                   if (k == i) continue;
                   int ptr = 0, x = 0;
                   while (ptr < 2) {
                       if (row[k][x].second == j) {
                           x++; continue;
                       } else {
                           tmp[k][ptr] = row[k][x];
                           ptr++, x++;
                       }
                   }


                   col[tmp[k][0].second].emplace_back(tmp[k][0].first, k);
                   col[tmp[k][1].second].emplace_back(tmp[k][1].first, k);
                   best[tmp[k][0].second].push_back(k);
               }
               vector<vector<pair<int, int>>> m1(2, vector<pair<int, int>>(n, make_pair(INT_MIN, -1)));
               vector<vector<pair<int, int>>> m2(2, vector<pair<int, int>>(n, make_pair(INT_MIN, -1)));

               auto add = [&](int val, int loc, int col, int t) {
                   if (val >= m1[t][col].first) {
                       m2[t][col] = m1[t][col];
                       m1[t][col] = make_pair(val, loc);
                   } else if (val >= m2[t][col].first) {
                       m2[t][col] = make_pair(val, loc);
                   }
               };


               for (int k = 0; k < n; k++) {
                   if (k > 0) {
                       m1[0][k] = m1[0][k - 1], m2[0][k] = m2[0][k - 1];
                   }
                   if (k == j) continue;
                   for (auto data : col[k]) {
                       add(data.first, data.second, k, 0);
                   }
               }
               for (int k = n - 1; k >= 0; k--) {
                   if (k < n - 1) {
                       m1[1][k] = m1[1][k + 1], m2[1][k] = m2[1][k + 1];
                   }
                   if (k == j) continue;
                   for (auto data : col[k]) {
                       add(data.first, data.second, k, 1);
                   }
               }


               for (int k = 0; k < n; k++) {
                   if (k == j) continue;
                   for (auto r : best[k]) {
                       int oth = INT_MIN;
                       if (k > 0) {
                           if (m1[0][k - 1].second != r) oth = max(oth, m1[0][k - 1].first);
                           if (m2[0][k - 1].second != r) oth = max(oth, m2[0][k - 1].first);
                       }
                       if (k < n - 1) {
                           if (m1[1][k + 1].second != r) oth = max(oth, m1[1][k + 1].first);
                           if (m2[1][k + 1].second != r) oth = max(oth, m2[1][k + 1].first);
                       }
                       ret = max(ret, 1ll * cur + tmp[r][0].first + oth);
                   }
               }
           }
       }
       return ret;
   }
};