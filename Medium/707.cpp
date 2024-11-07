struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    int length;

    MyLinkedList() {
        head = nullptr;
        length = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= this->length) {
            return -1;
        }
        Node* cur = this->head;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = this->head;
        this->head = newHead;
        this->length++;
    }
    
    void addAtTail(int val) {
        Node* cur = this->head;
        if (cur == nullptr) {
            this->addAtHead(val);
            return;
        }
        Node* newHead = new Node(val);
        for (int i = 0; i < this->length - 1; i++) {
            cur = cur->next;
        }
        cur->next = newHead;
        this->length++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > this->length) {
            return;
        }
        if (index == 0) {
            this->addAtHead(val);
            return;
        }
        Node* newHead = new Node(val);
        Node* cur = this->head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        newHead->next = cur->next;
        cur->next = newHead;
        this->length++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->length) {
            return;
        }
        if (index == 0) {
            this->head = this->head->next;
        } else {
            Node* cur = this->head;
            for (int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        this->length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */