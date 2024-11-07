class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adjRow(k), adjCol(k);
        for (auto e : rowConditions) {
            adjRow[e[0] - 1].push_back(e[1] - 1);
        }
        for (auto e : colConditions) {
            adjCol[e[0] - 1].push_back(e[1] - 1);
        }

        vector<vector<int>> ans;

        vector<int> colorRow(k);
        const function<bool(int)> dfsRow = [&](int v) -> bool {
            colorRow[v] = 1;
            for (int u : adjRow[v]) {
                if (colorRow[u] == 0) {
                    if (dfsRow(u)) return true;
                } else if (colorRow[u] == 1) {
                    return true;
                }
            }
            colorRow[v] = 2;
            return false;
        };

        vector<int> colorCol(k);
        const function<bool(int)> dfsCol = [&](int v) -> bool {
            colorCol[v] = 1;
            for (int u : adjCol[v]) {
                if (colorCol[u] == 0) {
                    if (dfsCol(u)) return true;
                } else if (colorCol[u] == 1) {
                    return true;
                }
            }
            colorCol[v] = 2;
            return false;
        };

        for (int v = 0; v < k; v++) {
            if (colorRow[v] == 0) {
                if (dfsRow(v)) return ans;
            }
        }
        for (int v = 0; v < k; v++) {
            if (colorCol[v] == 0) {
                if (dfsCol(v)) return ans;
            }
        }

        vector<bool> visRow(k);
        vector<int> tRow;
        const function<void(int)> topoRow = [&](int v) -> void {
            visRow[v] = true;
            for (int u : adjRow[v]) {
                if (!visRow[u]) topoRow(u);
            }
            tRow.push_back(v);
        };

        vector<bool> visCol(k);
        vector<int> tCol;
        const function<void(int)> topoCol = [&](int v) -> void {
            visCol[v] = true;
            for (int u : adjCol[v]) {
                if (!visCol[u]) topoCol(u);
            }
            tCol.push_back(v);
        };

        for (int i = 0; i < k; i++) {
            if (!visRow[i]) topoRow(i);
            if (!visCol[i]) topoCol(i);
        }

        reverse(tRow.begin(), tRow.end());
        reverse(tCol.begin(), tCol.end());

        vector<int> r(k), c(k);
        for (int i = 0; i < tRow.size(); i++) {
            r[tRow[i]] = i;
            c[tCol[i]] = i;
        }

        ans.assign(k, vector<int>(k));
        for (int i = 0; i < k; i++) {
            ans[r[i]][c[i]] = (i + 1);
        }
        return ans;
    }
};