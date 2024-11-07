class Encrypter {
public:
    vector<char> keys;
    map<char, int> key_pos;
    vector<string> values, dictionary;
    map<string, unordered_set<char>> sets;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        this->keys = keys;
        this->values = values;
        this->dictionary = dictionary;
        for (int i = 0; i < keys.size(); i++) {
            key_pos[keys[i]] = i;
            sets[values[i]].insert(keys[i]);
        }
    }

    string encrypt(string word1) {
        string ret;
        for (auto c : word1) {
            if (!key_pos.count(c)) return "";
            ret += values[key_pos[c]];
        }
        return ret;
    }
    
    int decrypt(string word2) {
        int n = word2.length();
        unordered_set<char> tmp[n / 2];
        for (int i = 0; i < n; i += 2) {
            if (!sets.count(word2.substr(i, 2))) {
                return 0;
            }
            tmp[i / 2] = sets[word2.substr(i, 2)];
        }

        int ret = 0;
        for (auto dct : dictionary) {
            if (dct.length() != n / 2) continue;
            bool ok = true;
            for (int i = 0; i < n / 2; i++) {
                if (!tmp[i].count(dct[i])) {
                    ok = false;
                    break;
                }
            }
            ret += ok;
        }
        return ret;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */