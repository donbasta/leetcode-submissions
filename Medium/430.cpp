/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
    
        function<vector<Node*>(Node*)> rec = [&](Node* h) -> vector<Node*> {
            Node* cur = h;
            Node* last = nullptr;
            while (cur != nullptr) {
                if (cur->child) {
                    vector<Node*> ch = rec(cur->child);
                    Node* tmp = cur->next;

                    ch[0]->prev = cur;
                    ch[1]->next = tmp;
                    cur->next = ch[0];
                    if (tmp) tmp->prev = ch[1];

                    cur->child = nullptr;
                    cur = tmp;
                    last = ch[1];
                } else {
                    last = cur;
                    cur = cur->next;
                }
            }
            return vector<Node*>{h, last};
        };
        vector<Node*> ve = rec(head);
        return ve[0];
    }
};