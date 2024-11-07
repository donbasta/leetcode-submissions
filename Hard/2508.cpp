class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1);
        vector<vector<int>> adj(n + 1);
        for (auto e : edges) {
            deg[e[0]]++, deg[e[1]]++;
            adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
        }
        int odd = 0;
        vector<int> ve;
        vector<int> other;
        for (int i = 1; i <= n; i++) {
            if (deg[i] & 1) {
                odd++;
                ve.push_back(i);
                if (deg[i] == n - 1) {
                    return false;
                }
            } else {
                if (deg[i] != n - 1) other.push_back(i);
            }
        }
        sort(other.begin(), other.end(), greater<>());
        if (odd > 4) return false;
        if (odd == 0) return true;
        if (odd == 2) {
            int a = ve[0], b = ve[1];
            sort(adj[a].begin(), adj[a].end());
            sort(adj[b].begin(), adj[b].end());
            vector<bool> A(n + 1), B(n + 1);
            for (auto c : adj[a]) A[c] = true;
            for (auto c : adj[b]) B[c] = true;
            if (A[b]) {
                int itr = 0;
                while (itr < (int)other.size() && (A[other[itr]] || B[other[itr]])) {
                    ++itr;
                }
                if (itr < (int)other.size() && n - 1 - deg[other[itr]] >= 2) return true;
                int x = 0, y = 0, z = 0;
                for (int i = 1; i <= n; i++) {
                    if (A[i] && B[i]) continue;
                    if (i == a || i == b) continue;
                    if (deg[i] % 2 == 0) continue;
                    if (!A[i] && !B[i]) z++;
                    else if (!A[i]) { x++; }
                    else if (!B[i]) { y++; }
                }
                if ((x + z >= 1) && (y + z >= 1) && (x + y + z >= 2)) return true;
                return false;
            }
            return true;
        }
        vector<vector<bool>> can(4, vector<bool>(4, true));
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                for (auto e : adj[ve[i]]) {
                    if (e == ve[j]) {can[i][j] = false; break;}
                }
            }
        }
        bool ok1 = can[0][1] && can[2][3];
        bool ok2 = can[0][2] && can[1][3];
        bool ok3 = can[0][3] && can[1][2];
        if (ok1 || ok2 || ok3) {
            return true;
        }
        if (!other.empty() && other[0] >= 4) return true;
        if (other.size() >= 2 && (other[0] + other[1] >= 4)) return true;
        return false;
    }
};