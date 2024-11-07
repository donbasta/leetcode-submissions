class Bitset {
public:
    vector<bool> bits;
    bool flipped = false;
    int c[2], sz;
    Bitset(int size) : sz(size) {
        bits.resize(size);
        c[0] = size;
        c[1] = 0;
    }
    
    void fix(int idx) {
        if (!(bits[idx] ^ flipped)) {
            c[bits[idx]] -= 1;
            bits[idx] = bits[idx] ^ true;
            c[bits[idx]] += 1;
        }
    }
    
    void unfix(int idx) {
        if (bits[idx] ^ flipped) {
            c[bits[idx]] -= 1;
            bits[idx] = bits[idx] ^ true;
            c[bits[idx]] += 1;
        }
    }

    void flip() {
        flipped ^= true;
    }

    bool all() {    
        return c[flipped ^ true] == sz;
    }

    bool one() {
        return c[flipped] != sz;
    }

    int count() {
        return c[flipped ^ true];
    }
    
    string toString() {
        string ret;
        for (auto b : bits) {
            if (b ^ flipped) ret += '1';
            else ret += '0';
        }
        return ret;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */