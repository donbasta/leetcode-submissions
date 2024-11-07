/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* ret = new Node(node->val);
    
        queue<Node*> Q, Q1;
        Q.push(node), Q1.push(ret);
    
        map<Node*, bool> vis;
        unordered_map<int, Node*> lol;
        lol[node->val] = ret;
        vis[node] = true;

        while (!Q.empty()) {
            Node *now = Q.front(), *now1 = Q1.front();
            Q.pop(), Q1.pop();
            for (auto n : now->neighbors) {
                if (vis.find(n) == vis.end()) {
                    vis[n] = true;
                    Node* nw = new Node(n->val);
                    lol[n->val] = nw;
                    now1->neighbors.push_back(nw);
                    Q.push(n);
                    Q1.push(nw);
                } else {
                    Node* ng = lol[n->val];
                    now1->neighbors.push_back(ng);
                }
            }
        }
        return ret;
    }
};