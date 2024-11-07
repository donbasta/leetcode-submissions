struct Node {
    vector<Node*> ch;
    string val;
    Node() {
        ch.resize(26);
        val = "";
    }
};

struct Trie {
    Node* head;
    Trie() {
        head = new Node();
    }
    void insert(string& s) {
        Node* cur = head;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            int tmp = s[i] - 'a';
            if (cur->ch[tmp] == nullptr) {
                cur->ch[tmp] = new Node();
            }
            cur = cur->ch[tmp];
        }
        cur->val = s;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        Trie t;
        for (auto w : words) t.insert(w);

        set<string> ada;
        bool vis[m][n];
        memset(vis, false, sizeof(vis));
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        const function<void(int, int, Node*&)> dfs = [&](int r, int c, Node*& cur) {
            if (cur->val != "") {
                ada.insert(cur->val);
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (vis[nr][nc]) continue;
                if (cur->ch[board[nr][nc] - 'a'] == nullptr) continue;

                vis[nr][nc] = true;
                dfs(nr, nc, cur->ch[board[nr][nc] - 'a']);
                vis[nr][nc] = false;
            }
        };
  
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (t.head->ch[board[i][j] - 'a'] == nullptr) continue;
                vis[i][j] = true;
                dfs(i, j, t.head->ch[board[i][j] - 'a']);
                vis[i][j] = false;
            }
        }

        vector<string> ret(ada.begin(), ada.end());
        return ret;
    }
};