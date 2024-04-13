class SinglyLinkedList;
class Node {
private:
    int data;
    Node* next;

public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    friend class SinglyLinkedList;
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void add_front(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void remove_front() {
        if (empty()) {
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    int front() {
        return head->data;
    }

    ~SinglyLinkedList() {
        while (!empty()) {
            remove_front();
        }
    }
};