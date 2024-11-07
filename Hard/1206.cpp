struct Node {
    Node* hori;
    Node* ver;
    int val;
    Node(int val = -1) : val(val) {
        hori = nullptr;
        ver = nullptr;
    }
};

class Skiplist {
public:
    vector<vector<Node*>> layers;
    Skiplist() {
        layers.resize(18);
        for (int i = 0; i < 18; i++) {
            layers[i].push_back(new Node());
        }
        for (int i = 17; i > 0; i--) {
            layers[i][0]->ver = layers[i - 1][0];
        }
    }
    
    bool search(int target) {
        Node* prv = layers[17][0];
        Node* cur = prv->hori;
        for (int j = 17; j >= 0; j--) {
            while (cur != nullptr && cur->val < target) {
                prv = cur, cur = cur->hori;
            }
            if (cur != nullptr && cur->val == target) return true;
            else {
                cur = prv->ver;
            }
        }
        return false;
    }
    
    void add(int num) {
        Node* prv = layers[17][0];
        Node* cur = prv->hori;
        vector<Node*> tmp;
        for (int j = 17; j > 0; j--) {
            while (cur != nullptr && cur->val < num) {
                prv = cur, cur = cur->hori;
            }
            tmp.push_back(prv);
            cur = prv->ver;
        }
        while (cur != nullptr && cur->val < num) {
            prv = cur, cur = cur->hori;
        }
        prv->hori = new Node(num);
        prv->hori->hori = cur;
        Node* nw = prv->hori;
        for (int j = 1; j < 18; j++) {
             double p = rand()/RAND_MAX;
             if (p < 0.5) {
                break;
             } else {
                Node* lmao = new Node(num);
                lmao->ver = nw;
                lmao->hori = tmp[17 - j]->hori;
                tmp[17 - j]->hori = lmao;
             }
        }
    }
    
    bool erase(int num) {
        Node* prv = layers[17][0];
        Node* cur = prv->hori;
        Node* start_buang = nullptr;
        Node* prv_buang = nullptr;
        for (int j = 17; j >= 0; j--) {
            while (cur != nullptr && cur->val < num) {
                prv = cur, cur = cur->hori;
            }
            if (cur != nullptr && cur->val == num) {
                prv_buang = prv;
                start_buang = cur;
                break;
            } else {
                cur = prv->ver;
            }
        }
        if (start_buang == nullptr) return false;

        while (true) {
            prv_buang->hori = start_buang->hori;
            start_buang = start_buang->ver;
            prv_buang = prv_buang->ver;
            if (start_buang == nullptr) {
                break;
            }
            while (prv_buang->hori != start_buang) prv_buang = prv_buang->hori;
        }
        return true;  
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */