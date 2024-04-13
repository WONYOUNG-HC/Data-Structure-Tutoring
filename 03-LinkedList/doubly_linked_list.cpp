class DoublyLinkedList;
class Node {
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    friend class DoublyLinkedList;
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void add_front(int data) {
        Node *new_node = new Node(data);
        if (empty()) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    void add_back(int data) {
        Node *new_node = new Node(data);
        if (empty()) {
            head = new_node;
            tail = new_node;
        } 
        else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void remove_front() {
        if (empty()) {
            return;
        }

        Node *tmp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }

        delete tmp;
    }

    void remove_back() {
        if (empty()) {
            return;
        }

        Node *tmp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } 
        else {
            head = nullptr;
        }

        delete tmp;
    }

    int front() {
        return head->data;
    }

    int back() {
        return tail->data;
    }

    ~DoublyLinkedList() {
        while (!empty()) {
            remove_front();
        }
    }
};
