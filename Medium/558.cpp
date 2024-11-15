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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node* ret = nullptr;
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            int x1 = quadTree1->val, x2 = quadTree2->val;
            return new Node(x1 | x2, true);
        }
        if (quadTree1->isLeaf) {
            int x1 = quadTree1->val;
            if (x1 == 1) return new Node(1, true);
            else return quadTree2;
        }
        if (quadTree2->isLeaf) {
            int x2 = quadTree2->val;
            if (x2 == 1) return new Node(1, true);
            else return quadTree1;
        }
        ret = new Node();
        ret->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        ret->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        ret->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        ret->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        bool check = ret->topLeft->isLeaf;
        int cval = ret->topLeft->val;
        check &= ret->topRight->isLeaf, check &= (ret->topRight->val == cval);
        check &= ret->bottomLeft->isLeaf, check &= (ret->bottomLeft->val == cval);
        check &= ret->bottomRight->isLeaf, check &= (ret->bottomRight->val == cval);
        if (check) {
            ret = new Node(cval, true);
        }
        return ret;
    }
};