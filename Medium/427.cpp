/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + (grid[i - 1][j - 1] == 1);
            }
        }
        const function<int(int, int, int, int)> getCountOnes = [&](int m1, int m2, int n1, int n2) -> int {
            int A = pref[m2 + 1][n2 + 1];
            int B = pref[m1][n2 + 1];
            int C = pref[m2 + 1][n1];
            int D = pref[m1][n1];
            return A - B - C + D;
        };

        const function<Node*(int, int, int, int)> rec = [&](int m1, int m2, int n1, int n2) -> Node* {
            int countSquares = (m2 - m1 + 1) * (n2 - n1 + 1);
            int countOnes = getCountOnes(m1, m2, n1, n2);
            if (countOnes == countSquares) {
                return new Node(true, true);
            } else if (countOnes == 0) {
                return new Node(false, true);
            }
            int m_mid = (m1 + m2) >> 1, n_mid = (n1 + n2) >> 1;
            Node* topLeft = rec(m1, m_mid, n1, n_mid); 
            Node* topRight = rec(m1, m_mid, n_mid + 1, n2);
            Node* bottomLeft = rec(m_mid + 1, m2, n1, n_mid);
            Node* bottomRight = rec(m_mid + 1, m2, n_mid + 1, n2);
            return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
        };

        return rec(0, m - 1, 0, n - 1);
    }
};