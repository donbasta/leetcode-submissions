class Graph {
private:
   int INF = 1e8;
   int n;
   vector<vector<int>> dis;
public:
   Graph(int n, vector<vector<int>>& edges) : n(n) {
       dis.resize(n);
       for (int i = 0; i < n; i++) dis[i].assign(n, INF);
       for (int i = 0; i < n; i++) dis[i][i] = 0;
       for (auto e : edges) {
           dis[e[0]][e[1]] = min(dis[e[0]][e[1]], e[2]);
       }
       for (int k = 0; k < n; k++) {
           for (int i = 0; i < n; i++) {
               for (int j = 0; j < n; j++) {
                   dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
               }
           }
       }
   }


   void addEdge(vector<int> edge) {
       int u = edge[0], v = edge[1], cost = edge[2];
       if (cost >= dis[u][v]) return;
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               dis[i][j] = min(dis[i][j], dis[i][u] + cost + dis[v][j]);
           }
       }
   }
  
   int shortestPath(int node1, int node2) {
       int d = dis[node1][node2];
       if (d == INF) return -1;
       return d;
   }
};


/**
* Your Graph object will be instantiated and called as such:
* Graph* obj = new Graph(n, edges);
* obj->addEdge(edge);
* int param_2 = obj->shortestPath(node1,node2);
*/
