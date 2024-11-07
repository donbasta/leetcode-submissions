struct Node {
    char val;
    Node* prev;
    Node* next;
    Node() : val(0), prev(nullptr), next(nullptr) {}
    Node(char val) : val(val), prev(nullptr), next(nullptr) {}
    Node(char val, Node* next, Node* prev) : next(next), prev(prev), val(val) {}
};

class TextEditor {
public:
    Node* cur = new Node('*');

    TextEditor() {}
    
    void addText(string text) {
        Node* newTextHead = new Node(text[0]);
        Node* tmp = newTextHead;
        for (int i = 1; i < text.length(); i++) {
            tmp->next = new Node(text[i]);
            tmp->next->prev = tmp;
            tmp = tmp->next;
        }
        tmp->next = cur->next;
        if (cur->next) cur->next->prev = tmp;
        cur->next = newTextHead;
        newTextHead->prev = cur;
        cur = tmp;
    }

    int deleteText(int k) {
        int cnt = 0;
        Node* newNext = cur->next;
        while ((cur->val != '*') && (cnt < k)) {
            cur = cur->prev;
            cnt++;
        }
        cur->next = newNext;
        if (newNext) newNext->prev = cur;
        return cnt;
    }

    string cursorLeft(int k) {
        int cnt = 0;
        while ((cur->val != '*') && (cnt < k)) {
            cur = cur->prev;
            cnt++;
        }
        string ret;
        int tmp = 0;
        Node* tmpPtr = cur;
        while ((tmpPtr->val != '*') && (tmp < 10)) {
            ret.push_back(tmpPtr->val);
            tmpPtr = tmpPtr->prev;
            tmp++;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    string cursorRight(int k) {
        int cnt = 0;
        while ((cur->next) && (cnt < k)) {
            cur = cur->next;
            cnt++;
        }
        string ret;
        int tmp = 0;
        Node* tmpPtr = cur;
        while ((tmpPtr->val != '*') && (tmp < 10)) {
            ret.push_back(tmpPtr->val);
            tmpPtr = tmpPtr->prev;
            tmp++;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */