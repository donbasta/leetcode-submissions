/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp, ump;
        Node* cur = head;
        Node* ret = new Node(head->val);
        Node* ans = ret;
        while (cur) {
            mp[ret] = cur;
            ump[cur] = ret;
            if (cur->next) {
                ret->next = new Node(cur->next->val);
            }
            cur = cur->next;
            ret = ret->next;
        }
        ret = ans;
        while (ret) {
            if (mp[ret]->random) {
                ret->random = ump[mp[ret]->random];
            }
            ret = ret->next;
        }
        return ans;
    }
};